#include		"donjon_master.hh"

void			limit_gravity(double			&posz,
				      double			destz,
				      double			vz)
{
  if ((posz + vz < destz+0.2
       && posz + vz > destz)
      || (posz + vz > destz-0.2
	  && posz + vz < destz))
    posz = destz;
  else
    posz += vz;
}
