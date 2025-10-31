#include		"donjon_master.hh"

double			rclamp(double			val,
			       double			min,
			       double			max)
{
  double		diff = val - max;

  if (diff > 0)
    return (min + diff);
  diff = val - min;
  if (diff < 0)
    return (max + diff);
  return (val);
}
