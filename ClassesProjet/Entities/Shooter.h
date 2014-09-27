


#ifndef SHOOTER_HEADER
#define SHOOTER_HEADER

#include "Bullet.h"


class Shooter
{
	public :

    Shooter(float nAmmo = 0, float nMaxAmmo = 0);
    void set(float nAmmo, float nMaxAmmo);

	virtual void trytoShoot(Bullet* what);
	void reload(float ammoAdded);

	protected :

	void shoot(Bullet* what);
	void shootProjectile(Bullet* what);
	float ammoUsed();

	float ammo();
	virtual float minAmmoToShoot();
	virtual float maxAmmo();

	private :

    float m_ammo;
    float m_maxAmmo;
//    BulletArray* m_target;
};



#endif

