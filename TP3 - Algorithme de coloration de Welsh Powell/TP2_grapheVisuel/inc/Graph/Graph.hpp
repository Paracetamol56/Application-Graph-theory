#pragma once
#include <LibGraph2.h>

#include "Edge.hpp"
#include "Node.hpp"

#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <algorithm>    // std::sort

class CGraph{
public:
	
	using pNodeSet = std::set<CNode::pNode>;
	using pEdgeSet = std::set<CEdge::pEdge>;

	CGraph() {};

	std::size_t GetNumberOfEdges() const { return m_spEdges.size(); }
	std::size_t GetNumberOfNodes() const { return m_spNodes.size(); }
	const pNodeSet& GetNodes() const { return m_spNodes; }
	const pEdgeSet& GetEdges() const { return m_spEdges; }

	void AddNewNode(CNode::pNode pNode) { m_spNodes.insert(pNode); }
	void AddNewEdge(CEdge::pEdge pEdge) {
		for (auto& pNode : pEdge->GetNodes())
			if (m_spNodes.count(pNode) == 0) // si cette arête référence un sommet non existant dans ce graphe
				return; // idéalement, un throw.
			else
				pNode->AddDegre(1);
		m_spEdges.insert(pEdge); }

	void RemoveEdge(CEdge::pEdge pEdge) {
		// On cherche l'arete dans le set d arete
		auto itpEdge = std::find(m_spEdges.begin(), m_spEdges.end(), pEdge); 
		if (itpEdge != m_spEdges.end())
		{
			for (auto& pNode : (*itpEdge)->GetNodes())
				pNode->SubDegre(1);
			m_spEdges.erase(itpEdge);
		}
		// else warning dans la console ?
	}

	void RemoveNode(CNode::pNode pNode) {
		// On cherche le noeud dans le set de noeud
		auto itpNode = std::find(m_spNodes.begin(), m_spNodes.end(), pNode); 
		// Si ce noeud existe
		if (itpNode != m_spNodes.end())
		{
			// On enleve toutes les aretes touchant ce noeud
			for (auto itpEdge = m_spEdges.begin(); itpEdge != m_spEdges.end();  )
			{
				if ((*itpEdge)->GetFirstNode() == (*itpNode) || (*itpEdge)->GetSecondNode() == (*itpNode))
					itpEdge = m_spEdges.erase(itpEdge);
				else
					itpEdge++;
			}
			// on enleve le noeud car il ne touche plus d arete
			m_spNodes.erase(itpNode);
		}
	}

	CNode::pNode GetNodeFromName(const std::string& name) const
	{
		// On parcourt le set de noeud et on renvoie celui qui a le bon nom
		for (auto& pNode : m_spNodes)
			if (pNode->GetName() == name)
				return pNode;
		// si non trouvé :
		return CNode::pNode(nullptr);
	}

	std::size_t GetNodeDegree(CNode::pNode pNode) const
	{
		std::size_t countDegree = 0;
		// Pour chaque arete si elle touche le noeud on incremente le degre
		for (auto const & pEdge : m_spEdges)
		{
			if (pEdge->GetFirstNode() == pNode)  
				++countDegree;
			if (pEdge->GetSecondNode() == pNode)
				++countDegree;
		}
		return countDegree;
	}

protected : 
	
	pEdgeSet m_spEdges; 
	pNodeSet m_spNodes;

	// TP 2 : 
public :

	void Clear() { m_spEdges.clear(); m_spNodes.clear(); }

	void ClearEdges() { m_spEdges.clear(); }

	bool CheckNodesAreNeighbors(CNode::pNode pNode1, CNode::pNode pNode2) const
	{
		for (auto const & pEdge : m_spEdges)
		{
			if (pEdge->GetFirstNode() == pNode1 && pEdge->GetSecondNode() == pNode2)
				return true;
			else if (pEdge->GetFirstNode() == pNode2 && pEdge->GetSecondNode() == pNode1)
				return true;
		}
		return false;
	}

	

	// TP2
	// TODO : On cherche le noeud le plus proche du point(x,y)
	// On initialise une distanceMin au max des float : FLT_MAX
	// Pour chaque noeud on calcule la distance euclienne entre lui et le point(x,y)
	// Si cette distance est inferieure a la distance min
	//       On met a jour la nouvelle distance et le pointeur sur le noeud le plus proche
	const CNode::pNode GetNodeNear(unsigned int x, unsigned int y) const 
	{ 
		float distMax = FLT_MAX; // max de distance 
		CNode::pNode pNodeNear = nullptr;
		// A FAIRE : 
		// On parcourt les noeuds du graphe
		// on cherche le noeud le plus proche du clic
		for (CNode::pNode i : m_spNodes)
		{
			float iDist = (x - i->GetX()) * (x - i->GetX()) + (y - i->GetY()) * (y - i->GetY());
			if (iDist < distMax)
			{
				distMax = iDist;
				pNodeNear = i;
			}
		}
		
		return pNodeNear;
	}

	// TP2
// TODO : On cherche l arete la plus proche du point(x,y)
// On initialise une distanceMin au max des float : FLT_MAX
// Pour chaque arete on calcule la distance euclienne entre le milieu de l arete et le point(x,y)
// Si cette distance est inferieure a la distance min
//       On met a jour la nouvelle distance et le pointeur sur l arete la plus proche
	const CEdge::pEdge GetEdgeNear(unsigned int x, unsigned int y) const
	{
		float distMax = FLT_MAX; // max de distance 
		CEdge::pEdge pEdgeNear = nullptr;
		// A FAIRE :
		// ON parcourt les arêtes du graphe 
		  // On cherche le milieu de l'arete le plus proche du clic
		for (CEdge::pEdge i : m_spEdges)
		{
			float iDist = (x - i->GetMilieuX()) * (x - i->GetMilieuX()) + (y - (i->GetMilieuY())) * (y - i->GetMilieuY());
			if (iDist < distMax)
			{
				distMax = iDist;
				pEdgeNear = i;
			}
		}
	
		return pEdgeNear;
	}
};
