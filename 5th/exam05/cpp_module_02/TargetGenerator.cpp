#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator(void)
{
}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if (target)
		_targetMap[target->getType()] = target;
}

void TargetGenerator::forgetTargetType(std::string const &targetType)
{
	std::map<std::string, ATarget *>::iterator it = _targetMap.find(targetType);
	if (it != _targetMap.end())
	{
		delete it->second;
		_targetMap.erase(it);
	}
}

ATarget *TargetGenerator::createTarget(std::string const &targetType)
{
	std::map<std::string, ATarget *>::iterator it = _targetMap.find(targetType);
	if (it != _targetMap.end())
		return (_targetMap[targetType]);
	return (NULL);
}
