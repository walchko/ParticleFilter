#include <iostream>
#include <particleFilter.h>

using namespace std;
using namespace cv;

ParticleFilter::ParticleFilter() 
{
  // Initialize class members
  char name1[] = "../data/map/wean.dat";
  weanMapName = name1;
  weanMap = MyMap();
  image = Mat(800,800,CV_32FC3);
  frame = Mat(800,800,CV_32FC3);

  logName = "../data/log/robotdata1.log";

  numParticles = 10000;

  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator(seed);
  normal = std::normal_distribution<double>(0.0,5.0);
}

int main()
{
	// Setup for random number generator
	srand(time(NULL));

  // Initialize our particle filter
  ParticleFilter filter;

	// Load occupancy map of wean hall and data from log
  filter.readMap();
  filter.loadMapImage();
  filter.readLog();

  // Draw initial particles
  filter.drawParticles();

  // Start the filter!
  for (int i = 1; i < filter.timestamps.size(); i++) {
    filter.motionModel(i);
    // filter.calculateWeights();
    // filter.resampleParticles();
    filter.visualize();
  }

  std::cout << "Done!\n";
}