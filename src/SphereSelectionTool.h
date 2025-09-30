#ifndef SphereSelectionTool_H
#define SphereSelectionTool_H
#include "Vec3.h"


struct SphereSelectionTool
{
	float radius;
	Vec3 center;
	bool isAdding;
	bool isActive;

	SphereSelectionTool() : radius(1.0), center(0.0, 0.0, 0.0), isAdding(false), isActive(false) {}


	void initSphere(const Vec3& pCenter, const float &pRadius)
	{
		// init sphere with Vec3 center and radius
		center = pCenter;
        radius = pRadius;
        isActive = true;
	}

	void updateSphere(float pRadius)
	{
		// update radius 
		radius = pRadius;
	}

	bool contains (const Vec3& p)
	{
		// is point p in sphere (center_x, center_y, center_z), radius) ?
		float dx = p[0] - center[0];
        float dy = p[1] - center[1];
        float dz = p[2] - center[2];
        float dist2 = dx*dx + dy*dy + dz*dz;
        return dist2 <= radius*radius;
	}


	void draw() {
	    if(!isActive) return;
	    // draw Sphere
		glPushMatrix();
        glTranslatef(center[0], center[1], center[2]);
        glColor4f(1.0, 0.0, 0.0, 0.3f);
        glutSolidSphere(radius, 20, 20);
        glPopMatrix();
	}
};
#endif