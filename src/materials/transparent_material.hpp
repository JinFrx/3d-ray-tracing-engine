#ifndef __RT_ISICG_TRANSPARENT_MATERIAL__
#define __RT_ISICG_TRANSPARENT_MATERIAL__

#include "base_material.hpp"

namespace RT_ISICG
{
	class TransparentMaterial : public BaseMaterial
	{
	  public:
		TransparentMaterial( const std::string & p_name, const float p_ior = 1.3f )
			: BaseMaterial( p_name ), _ior( p_ior )
		{
		}

		virtual ~TransparentMaterial() = default;

		Vec3f shade( const Ray &		 p_ray,
					 const HitRecord &	 p_hitRecord,
					 const LightSample & p_lightSample ) const override
		{
			return BLACK;
		}

		inline const Vec3f & getFlatColor() const override { return BLACK; }

		inline const float getIOR() const override { return _ior; }

		inline const bool isTransparent() const override { return true; }
	
	  private:
		float _ior;
	};

} // namespace RT_ISICG

#endif // __RT_ISICG_TRANSPARENT_MATERIAL__