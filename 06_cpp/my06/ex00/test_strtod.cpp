/* strtod example */
#include <iostream>      /* printf, NULL */
#include <cstdlib>     /* strtod */

int main ()
{
  char szOrbits[] = "365.24 29.53";
  char* pEnd;
  double d1, d2;
  d1 = std::strtod (szOrbits, &pEnd);
  d2 = std::strtod (pEnd, NULL);
  std::cout << "The moon completes " << d1/d2 << " orbits per Earth year." << std::endl;
  return 0;
}
