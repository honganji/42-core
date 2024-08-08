#ifndef TARGET_GENERATOR_HPP
#define TARGET_GENERATOR_HPP

#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
	protected:

	private:
	  std::map<std::string, ATarget *> _targetMap;

	public:
	  TargetGenerator();
	  ~TargetGenerator(void);
	  void learnTargetType(ATarget *target);
	  void forgetTargetType(std::string const &targetType);
	  ATarget *createTarget(std::string const &targetType);
};

#endif
