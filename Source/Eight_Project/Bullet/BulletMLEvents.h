// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

// #include "bulletmlparser.h"
// #include "bulletmlparser-tinyxml.h"
#include "bulletmlrunner.h"

/**
 * 
 */
class EIGHT_PROJECT_API BulletMLEvents : public BulletMLRunner {
public:
	// BulletMLEvents();
	// ~BulletMLEvents();

	// ----- Start of functions that must absolutely be implemented -----
	///
    //@{

	/// Find the angle of the bullet
    /**
     * @return Return angle in degrees, clockwise in upward direction 0
     */
    virtual double getBulletDirection();

	/// Find the angle that aims at your ship from this bullet
    /**
     * @return Returns the angle in degrees, clockwise with 0 at the top
     */
    virtual double getAimDirection();

	/// Find the speed of this bullet
    virtual double getBulletSpeed();

	/// Find the default speed
    virtual double getDefaultSpeed();

	/// Ask for a rank
    /**
     * @return Real number from 0 to 1
     */
    virtual double getRank();

	/// Make bullets without an action
    virtual void createSimpleBullet(double direction, double speed);

	/// Make a bullet with an action
    /**
     * @param state
	 * Passing it to the new bullet BulletMLRunner's constructor.
	 * If you do not pass it you have to release it with delete.
	 */
    virtual void createBullet(BulletMLState* state, double direction, double speed);

	/// It returns the value of the turn which becomes the reference of the
	/// bullet, usually the number of frames
    /**
     * @return
	 * You can change the order according to the standard of each game,
	 * but negative numbers are not allowed.
     * There is no problem as long as the order of wait and term is on
	 * the xml data.
     */
    virtual int getTurn();

	/// Die
    virtual void doVanish();

    //@}
	// ----- End of functions that must absolutely be implemented -----

	// ----- Start of functions to be implemented if necessary -----
    //@{

	/// Change direction of bullet to specified direction
    virtual void doChangeDirection(double) {}

	/// Change the speed of the bullet to the specified value
    virtual void doChangeSpeed(double) {}

	/// Interface to accel
    /**
     * @todo
	 * The horizontal and vertical types are not implemented yet.
     * It will become absolute as well.
     */
    virtual void doAccelX(double) {}

	/// Interface to accel
    /**
     * @todo
	 * The horizontal and vertical types are not implemented yet.
	 * It will become absolute as well.
	 */
    virtual void doAccelY(double) {}

	/// Returns the X direction component of the bullet speed
    /**
	 * Override when using accel
     */
    virtual double getBulletSpeedX() { return 0; }

	/// Returns the Y direction component of bullet speed
    /**
	 * Override when using accel
     */
    virtual double getBulletSpeedY() { return 0; }

    //@}
	// ----- End of functions to be implemented if necessary -----

	/// Returns a random number
    /**
	 * As you can see, std::rand is used by default.
     */
    virtual double getRand() { return (double)rand() / RAND_MAX; }
};
