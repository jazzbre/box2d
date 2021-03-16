/*
* Copyright (c) 2006-2009 Erin Catto http://www.box2d.org
* Copyright (c) 2013 Google, Inc.
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

#ifndef B2_PARTICLESETTINGS_H
#define B2_PARTICLESETTINGS_H

#include "box2d/b2_settings.h"

// Particle

/// NEON SIMD requires 16-bit particle indices
#if !defined(B2_USE_16_BIT_PARTICLE_INDICES) && defined(LIQUIDFUN_SIMD_NEON)
#define B2_USE_16_BIT_PARTICLE_INDICES
#endif

/// A symbolic constant that stands for particle allocation error.
#define b2_invalidParticleIndex		(-1)

#ifdef B2_USE_16_BIT_PARTICLE_INDICES
#define b2_maxParticleIndex			0x7FFF
#else
#define b2_maxParticleIndex			0x7FFFFFFF
#endif

/// The default distance between particles, multiplied by the particle diameter.
#define b2_particleStride			0.75f

/// The minimum particle weight that produces pressure.
#define b2_minParticleWeight			1.0f

/// The upper limit for particle pressure.
#define b2_maxParticlePressure		0.25f

/// The upper limit for force between particles.
#define b2_maxParticleForce		0.5f

/// The maximum distance between particles in a triad, multiplied by the
/// particle diameter.
#define b2_maxTriadDistance			2
#define b2_maxTriadDistanceSquared		(b2_maxTriadDistance * b2_maxTriadDistance)

/// The initial size of particle data buffers.
#define b2_minParticleSystemBufferCapacity	256

/// The time into the future that collisions against barrier particles will be detected.
#define b2_barrierCollisionTime 2.5f

/// This is a approximate yet fast inverse square-root.
inline float b2InvSqrt(float x)
{
	union
	{
		float x;
		int32 i;
	} convert;

	convert.x = x;
	float xhalf = 0.5f * x;
	convert.i = 0x5f3759df - (convert.i >> 1);
	x = convert.x;
	x = x * (1.5f - xhalf * x * x);
	return x;
}

#define	b2Sqrt(x)	sqrtf(x)
#define	b2Atan2(y, x)	atan2f(y, x)

#endif
