

#ifndef CAMPAIGN_HEADER
#define CAMPAIGN_HEADER


class Campaign : public AbstractGameInterface<float>
{
    public :

    Campaign();
    void setResources(TextureList* t, ResourceList<EnemiesStats>* statsList);

    void setLevel();

    void drawIn(AbstractDrawer& window);
    void update(const float& dt);


    private :

    BasicSpaceLevel* m_level;

    const json::Document* m_levelList;
    size_t m_selectedLevel;

    TextureList* m_textures;
    ResourceList<EnemiesStats>* m_stats;
};



#endif // CAMPAIGN_HEADER

