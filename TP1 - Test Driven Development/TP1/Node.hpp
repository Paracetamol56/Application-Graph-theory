#pragma once

#include <string>
#include <memory>

class CNode {

public:
	using pNode = std::shared_ptr<CNode>;

	CNode(const std::string& name = std::string()) { SetName(name); }
	std::string GetName() const { return m_Name; }
	void SetName(const std::string& n) { m_Name = n; }

protected:
	std::string m_Name;
	// will later hold more infos
};