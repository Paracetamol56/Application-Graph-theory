#pragma once

#include "Edge.hpp"

#include <memory>
#include <set>
#include <vector>
#include <iostream>

class CGraph{

public:
	
	using NodeSet = std::set<CNode::pNode> ;
	using EdgeSet = std::set<CEdge::pEdge> ;

	CGraph() {};

	// GETTER
	std::size_t GetNumberOfEdges() const { return m_spEdges.size(); }
	std::size_t GetNumberOfNodes() const { return m_spNodes.size(); }
	const NodeSet& GetNodes() const { return m_spNodes; }
	const EdgeSet& GetEdges() const { return m_spEdges; }

	void AddNewNode(CNode::pNode pNode) { m_spNodes.insert(pNode); }
	void AddNewEdge(CEdge::pEdge pEdge) { m_spEdges.insert(pEdge); }

	void RemoveEdge(CEdge::pEdge pEdge)
	{
		m_spEdges.erase(m_spEdges.find(pEdge));
	}

	void RemoveNode(CNode::pNode pNode)
	{
		for (EdgeSet::iterator it = m_spEdges.begin(); it != m_spEdges.end();)
		{
			if ((*it)->GetFirstNode() == pNode || (*it)->GetSecondNode() == pNode)
				it = m_spEdges.erase(it);
			else
				++it;
		}
		m_spNodes.erase(m_spNodes.find(pNode));
	}

	CNode::pNode GetNodeFromName(const std::string& name) const
	{ 
		for (NodeSet::iterator it = m_spNodes.begin(); it != m_spNodes.end(); ++it )
		{
			if ((*it)->GetName() == name)
				return *it;
		}
		return nullptr;
	}
	CNode::pNode GetNodeFromReference(const CNode& node) const
	{
		return GetNodeFromName(node.GetName());
	}
	
	std::size_t GetNodeDegree(CNode::pNode node) const
	{
		size_t degree = 0;
		for (CEdge::pEdge it : m_spEdges)
		{
			if (it->GetFirstNode() == node)
				++degree;
			if (it->GetSecondNode() == node)
				++degree;
		}
		return degree;
	}
	
private : 
	
	EdgeSet m_spEdges; // un set d'aretes et de noeuds
	NodeSet m_spNodes;
};



std::ostream& operator<<(std::ostream& os, const CGraph& g)
{
	os << "\n";
	os << "\tGraph : " << std::endl;
	os << "\tSommets : " << g.GetNumberOfNodes() << "   ";
	for (const auto& pNode : g.GetNodes()) os << "  " << pNode->GetName() << ", ";
	os << std::endl << "\tAretes : " << g.GetNumberOfEdges() << "   ";
	for (const auto& pEdge : g.GetEdges())
	{
		os << "  ";
		for (const auto& pNode : pEdge->GetNodes())
			os << pNode->GetName() << "->";
		os << pEdge->GetWeight() << " ,    ";
	}
	os << "\n";
	return os;
}