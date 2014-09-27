

#ifndef STRAFFER_HEADER
#define STRAFFER_HEADER

#include "../AI/AbsStraffAI.h"
#include "../Moteur2D.h"


class Straffer
{
	public :

	struct Para;

    Straffer() {}
    Straffer(AbstractStraffAI* ai, float normalSpeed, float boostValue, float leftLimit, float rightLimit);
    Straffer(const Para& parameters, AbstractStraffAI* ai = 0);
    void set(const Para& parameters);
    void set(float normalSpeed, float boostValue, float leftLimit, float rightLimit);
    void set(AbstractStraffAI* ai);
/*
	void setLeftLimit(float value);
	void setRightLimit(float value);
	virtual void setBoostValue(float value);
	virtual void setNormalSpeed(float value);
*/
    void update(float ticks);
    void replaceObject();


	protected :

	bool isBoostActivated();
	virtual float boostValue();

	virtual void moveLR(float ticks) = 0;
	virtual float leftPos() = 0;
	virtual float rightPos() = 0;

	void applySpeed(float ticks);
	void startBoost();
    void stopBoost();


	private :

	float m_normalSpeed;
	float m_boostValue;
	bool b_boostActive;

	float m_limitLeft;
	float m_limitRight;

	AbstractStraffAI* m_ai;


	public :

	struct Para
	{
	    float normalSpeed;
	    float boostValue;
	    float leftLimit;
	    float rightLimit;

	    Para(float nNormalSpeed, float nBoostValue, float nLeftLimit, float nRightLimit) :
	    normalSpeed(nNormalSpeed), boostValue(nBoostValue), leftLimit(nLeftLimit), rightLimit(nRightLimit)
        { }
	};
};






#endif


