#pragma once
#include "Solid.h"
#include "Color.h"
class Triangle : public Solid {
		Vector3D p0;	
		Vector3D p1;
		Vector3D p2;
		Vector3D n0;
		Vector3D n1;
		Vector3D n2;
		Color c0, c1, c2;
	public:

		Triangle(Vector3D point0, Vector3D point1, Vector3D point2, Vector3D normal0, Vector3D normal1, Vector3D normal2) :
		 p0(point0), p1(point1), p2(point2), n0(normal0), n1(normal1), n2(normal2)
		{
			c0 = c1 = c2 = Color(0.0, 0.0, 0.0);
		}
		Vector3D getP0() { return p0; }
		Vector3D getP1() { return p1; }
		Vector3D getP2() { return p2; }
		Vector3D getN0() { return n0; }
		Vector3D getN1() { return n1; }
		Vector3D getN2() { return n2; }
		Color getC0() { return c0; }
		Color getC1() { return c1; }
		Color getC2() { return c2; }

		void setP0(Vector3D pt0) { pt0 = p0; }
		void setP1(Vector3D pt1) { pt1 = p1; }
		void setP2(Vector3D pt2) { pt2 = p2; }
		void setN0(Vector3D nl0) { nl0 = n0; }
		void setN1(Vector3D nl1) { nl1 = n1; }
		void setN2(Vector3D nl2) { nl2 = n2; }

		void setC0(Color c0) { c0 = c0; }
		void setC1(Color c1) { c1 = c1; }
		void setC2(Color c2) { c2 = c2; }
		
		void setVertex(Vector3D p0, Vector3D p1, Vector3D p2){}
		void setNormal(Vector3D n0, Vector3D n1, Vector3D n2){}

		void Render();
	
	
};


