


#ifndef HEADER_BOUCLE
#define HEADER_BOUCLE

#include "Moteur2D.h"
#include "Levels/loadFromFile.h"
#include <fstream>
#include "MainDimensions.h"
#include "Levels/FirstScreen.h"
#include "Levels/SpaceHUD.h"
#include "Levels/RandomSpaceLevel.h"

#define TITRE_FENETRE "Spaceship !"
#define FRAMERATE 60
#define FRAME_SIZE (1.0f / FRAMERATE) * 2

#define MAIN_DATABASE "Ressources\\DatabaseFile.txt"
#define COMMAND_FILE  "Ressources\\CommandFile.txt"



class BoucleJeu : public GameController<float>
{
    public :

    explicit BoucleJeu(AbstractInputs* tableauEntrees = nullptr, sf::RenderWindow* cible = nullptr);
    void setDatabase(sql3::Database& db, const char* mainDatabaseName, const char* commandFileName);
    void setTextures(TextureList& t);
    void setLevel(RandomSpaceLevel* level, TextureList& t, sql3::Database& db);
    void setHUD(TextureList& t, SpaceHUD* hud);

    virtual void update(float tickSize);                // updates everything in the game
    virtual void drawEverything(float tickSize);
    virtual AbstractGameInterface<float>* interface();


    private :

    sf::RenderWindow* m_window;             //use-a
    MetaInterface<float> m_interface;

    TextureList m_textureList;
//    WaveSpaceLevel* m_level; // has-a
    RandomSpaceLevel* m_level;  /// TO CHANGE

};


#endif
