#include "../synchronization/EBaseMutualExclusion.hpp"

EToolkit::BaseMutualExclusion::BaseMutualExclusion() :
	state(BaseMutualExclusion::Empty){

}

EToolkit::BaseMutualExclusion::~BaseMutualExclusion(){

}

EToolkit::BaseMutualExclusion::State EToolkit::BaseMutualExclusion::getState() const{
	return state;
}
