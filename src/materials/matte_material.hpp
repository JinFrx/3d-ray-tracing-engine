#ifndef __RT_ISICG_MATTE_MATERIAL__
#define __RT_ISICG_MATTE_MATERIAL__

#include "base_material.hpp"
#include "brdfs/oren_nayar_brdf.hpp"

namespace RT_ISICG
{
	class MatteMaterial : public BaseMaterial
	{
	  public:
		MatteMaterial( const std::string & p_name, const Vec3f & p_diffuse, const float p_slope )
			: BaseMaterial( p_name ), _brdf( p_diffuse, p_slope )
		{
		}

		virtual ~MatteMaterial() = default;

		Vec3f shade( const Ray &		 p_ray,
					 const HitRecord &	 p_hitRecord,
					 const LightSample & p_lightSample ) const override
		{
			// penser a inverser la direction du rayon, pour avoir les memes directions que sur le modele : ^\|/^ et pas \v|/^
			return _brdf.evaluate( p_hitRecord._normal, -normalize(p_ray.getDirection()), normalize(p_lightSample._direction) );
		}

		inline const Vec3f & getFlatColor() const override { return _brdf.getKd(); }

	  protected:
		OrenNayarBRDF _brdf;

	};
} // namespace RT_ISICG

#endif // __RT_ISICG_MATTE_MATERIAL__