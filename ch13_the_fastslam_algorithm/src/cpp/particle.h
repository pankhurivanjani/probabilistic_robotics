#define ARMA_USE_HDF5
//#define ARMA_USE_SUPERLU 1
#define ARMA_64BIT_WORD
#define DARMA_DONT_USE_WRAPPER

#include "btree.h"

class Particle{

public:
  Particle():
    particleCount(100),
    position(3,100,fill::zeros),
    weight(100,fill::ones)
    {b_trees = new BTree[100];}

  Particle(uint n):
    particleCount(n),
    position(3,n,fill::zeros),
    weight(n,fill::ones)
    {b_trees = new BTree[n];}

  ~Particle(){
    delete[] b_trees;
  }

  void motion(double,double,double,mat z);
  void resample();
  void print(std::ostream&) const;

private:
  unsigned int  const particleCount;
  mat position;
  vec weight;
  BTree* b_trees;

  void motion_measurement(double,double,double,mat);

};

std::ostream& operator<< (std::ostream&, const BTree&);
std::ostream& operator<< (std::ostream&, const Particle&);
