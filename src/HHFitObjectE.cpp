#include "HHFitObjectE.h"
#include <iostream>
#include <iomanip>


HHFitObjectE::HHFitObjectE(HHLorentzVector const& initial4vector)
  :HHFitObject(initial4vector),
   m_upperLimitE(9999999),
   m_lowerLimitE(0){

}

void
HHFitObjectE::changeEandSave(Double_t E){
  this->setFit4Vector(changeE(E));
}

void
HHFitObjectE::scaleEandSave(Double_t E){
  this->setFit4Vector(scaleE(E));
}

void
HHFitObjectE::constrainEtoMinvandSave(Double_t m, HHLorentzVector const& other4vector){
  this->setFit4Vector(constrainEtoMinv(m, other4vector));
}

Double_t
HHFitObjectE::getE() const{
  return(m_fit4vector.E());
}

Double_t
HHFitObjectE::getUpperFitLimitE() const{
  return(m_upperLimitE);
}

Double_t
HHFitObjectE::getLowerFitLimitE() const{
  return(m_lowerLimitE);
}

void
HHFitObjectE::setUpperFitLimitE(Double_t upperlimit){
  m_upperLimitE = upperlimit;
}

void
HHFitObjectE::setUpperFitLimitE(Double_t minv, HHLorentzVector const& other4vectorMin){
  this->setUpperFitLimitE(constrainEtoMinv(minv,other4vectorMin).E());
}

void
HHFitObjectE::setLowerFitLimitE(Double_t lowerlimit){
  m_lowerLimitE = lowerlimit;
}

void
HHFitObjectE::setLowerFitLimitE(HHLorentzVector const& lowerlimit){
  m_lowerLimitE = lowerlimit.E();
}

void
HHFitObjectE::print() const{
  std::cout << "---" << std::endl;
  std::cout << "energy component fit object:" << std::endl;
  this->printInitial4Vector();
  this->printFit4Vector();
  this->printLimits();
  this->printCovMatrix();
}


void
HHFitObjectE::printLimits() const{
  std::cout <<  "limits: "
            << std::setw(10) << std::fixed<< std::setprecision(1) << this->getLowerFitLimitE()
            << std::setw(10) << std::fixed<< std::setprecision(1) << this->getUpperFitLimitE()
            << std::endl;
}

