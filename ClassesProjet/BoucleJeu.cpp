

#include "BoucleJeu.h"


BoucleJeu::BoucleJeu(AbstractInputs* tableauEntrees, sf::RenderWindow* cible) : m_level(new RandomSpaceLevel)
{
    m_window = cible;
    set(tableauEntrees, cible);
    m_level->setUserInputs(windowInputs());

    SpaceHUD* hud = new SpaceHUD(m_level);
    m_interface.addInterface(hud);

    sf::Font f;
    f.loadFromFile(DEFAULT_FONT_NAME);
    m_interface.addInterface(new FirstScreen(f, sf::Color::White, windowInputs()));

    drawEverything(0);

    sql3::Database db;
    setDatabase(db, MAIN_DATABASE, COMMAND_FILE);
    setTextures(m_textureList);
    setLevel(m_level, m_textureList, db);
    setHUD(m_textureList, hud);
}



void BoucleJeu::setDatabase(sql3::Database& db, const char* mainDatabaseName, const char* commandFileName)
{
    std::ifstream file(commandFileName);

    if (file.is_open())
    createDatabaseFromFile(db, file, mainDatabaseName, &std::cerr, true);

    else
    db.open(mainDatabaseName);
}


void BoucleJeu::setTextures(TextureList& t)
{
    std::map<std::string, std::string> textures;

    textures[LIFE_TEXTURE_NAME] = "Ressources\\Images\\Vie.bmp";
    textures[IDLE_PLAYER_TEXTURE_NAME] = "Ressources\\Images\\Vaisseau_Joueur.bmp";
    textures[SHOOTING_PLAYER_TEXTURE_NAME] = "Ressources\\Images\\Vaisseau_Joueur_Charge.bmp";
    textures[PLAYER_BULLET_SPRITE_NAME] = "Ressources\\Images\\Tir.bmp";
    textures[DEFAULT_ENEMY_SHOT_NAME] = "Ressources\\Images\\Tir_Ennemi.bmp";

    t.loadBaseTextures(textures);
}


void BoucleJeu::setLevel(RandomSpaceLevel* level, TextureList& t, sql3::Database& db)
{
    level->setZones(sf::IntRect(0,0, LARGEUR_FENETRE, HAUTEUR_FENETRE), 0, LARGEUR_FENETRE, HAUTEUR_SPAWN);
    level->useTextureList(&t);

    level->respawnPlayer();

    loadTextureList(t, db);
    loadEnemyStats(*level, db);
///    loadEnemyWave(*level, db);                               - TO CHANGE

    std::vector<std::string> names = {"mook", "boosted", "shooter", "invis"};
    level->setNames(names);
    level->setLives(NUMBER_OF_LIVES);
}


void BoucleJeu::setHUD(TextureList& t, SpaceHUD* hud)
{
    hud->setAllFonts(DEFAULT_FONT_NAME);
    hud->setLifeSprite(sf::Sprite( *t.texture(LIFE_TEXTURE_NAME) ));
}




AbstractGameInterface<float>* BoucleJeu::interface()
{
    return &m_interface;
}



void BoucleJeu::drawEverything(float tickSize)
{
    m_interface.drawIn(*renderingWindow());
}


void BoucleJeu::update(float tickSize)
{
    interface()->update(tickSize);
    windowInputs()->update();

    drawEverything(tickSize);
}





