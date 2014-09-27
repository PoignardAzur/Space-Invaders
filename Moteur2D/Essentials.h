

class Vart
{
    public :
    Vart(Sprite* sprite = 0, sf::IntRect parametres = RECT_NUL, sf::Vector2f position = PT_NUL, sf::Vector2f vitesse = PT_NUL);
    virtual void update(float tickSize);

    protected :
    void setSprite(Sprite* para); // Setters
    void setHitbox(const PhysicObject&);
    virtual void removeThis();
};


class PhysicObject
{
    PhysicObject(sf::IntRect parametres = RECT_NUL, sf::Vector2f position = PT_NUL, sf::Vector2f vitesse = PT_NUL, sf::Vector2f acceleration = PT_NUL);

    sf::IntRect absoluteBox() const;
    sf::IntRect relativeBox() const;
    sf::Vector2f gap() const;

    void move(sf::Vector2f nposition, bool relatif = false);
    virtual void changeSpeed(sf::Vector2f nvitesse, bool relatif = false);
	virtual void changeAcceleration(sf::Vector2f nvitesse, bool relatif = false);

    sf::Vector2f position() const;
    sf::Vector2f speed() const;
    sf::Vector2f acceleration() const;
};


template <typename T>
class VartArray
{
    VartArray();

    void add(T* nvart);
    std::vector< boost::shared_ptr<T> >& array();
    boost::shared_ptr<T> objectN(unsigned short lequel);
    unsigned short size() const;
    void clear();

    void update(float tickSize); // Quand le tableau est mis à jour, tous ses éléments le sont.
    void drawIn(AbstractDrawer& cible); // Quand le tableau est affiche, tous ses éléments le sont.


    protected :
    void remove(int lequel);
    void deleteVarts();
};


class ObjectDrawer : public AbstractDrawer
{
    public :

    ObjectDrawer(sf::RenderWindow* cible);
    sf::RenderTarget& target();

    void clear();
    void draw(const AbstractDrawable& objet);
    void display();
};


class Sprite : public DrawableObject
{
    public :

    Sprite() {}
    Sprite(const sf::Sprite& image);
    void set(const sf::Sprite& image);
    void setPosition(const sf::Vector2f& nposition); // define better ?
	
    void drawIn(AbstractDrawer& cible) const;
    void update(float tickSize) {}

    protected :
    virtual const sf::Drawable& sprite() const;
    virtual sf::Drawable& sprite();
};






