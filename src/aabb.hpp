#ifndef __RT_ISICG_AABB__
#define __RT_ISICG_AABB__

#include "ray.hpp"
#include <vector>

namespace RT_ISICG
{
	struct AABB
	{
	  public:
		AABB() = default;
		AABB( const Vec3f & p_min, const Vec3f & p_max ) : _min( p_min ), _max( p_max ) {}
		~AABB() = default;

		inline const Vec3f & getMin() const { return _min; }
		inline const Vec3f & getMax() const { return _max; }

		// Returns true if the AABB is degenerated.
		inline bool isValid() const { return ( ( _min.x <= _max.x ) && ( _min.y <= _max.y ) && ( _min.z <= _max.z ) ); }

		// Extends the AABB with a point
		void extend( const Vec3f & p_point );
		// Extends the AABB with another AABB
		void extend( const AABB & p_aabb );
		
		// Returns the AABB diagonal vector.
		inline Vec3f diagonal() const { return _max - _min; }

		// Returns the AABB centroid.
		inline Vec3f centroid() const { return ( _min + _max ) * 0.5f; }

		// Returns the largest axis, 0 -> x, 1 -> y, 2 -> z
		inline size_t largestAxis() const
		{
			const Vec3f d = diagonal();
			if ( d.x > d.y && d.x > d.z )
				return 0;
			else if ( d.y > d.z )
				return 1;
			else
				return 2;
		}

		bool intersect( const Ray & p_ray, const float p_tMin, const float p_tMax ) const;

		// Calcul de l'aire surfacique de la AABB
		inline float computeSurfaceArea() const
		{
			const Vec3f d = diagonal();

			return 2.f * ( d.x * d.y + d.x * d.z + d.y * d.z );
		}

	  private:
		Vec3f _min = Vec3f( FLT_MAX );
		Vec3f _max = Vec3f( -FLT_MAX );
	};

} // namespace RT_ISICG

#endif // __RT_ISICG_AABB__
