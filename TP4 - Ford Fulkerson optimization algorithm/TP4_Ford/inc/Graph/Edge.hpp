#pragma once

#include "Node.hpp"

#include <array>
#include <memory>

class CEdge 
{
public : 
	using  pEdge = std::shared_ptr<CEdge> ;// Alias pour pointeur sur noeud
	using   pNodeArray = std::array<CNode::pNode, 2>; 
	static pEdge New(CNode::pNode pNode1, CNode::pNode pNode2, size_t weight = 0) { return std::make_shared<CEdge>(pNode1, pNode2, weight); }

	CEdge(CNode::pNode pNode1, CNode::pNode pNode2, size_t weight)
		: m_dWeight(weight), m_apNodes{ pNode1,pNode2 } {}

	// TP 1 :
	// TODO : ajouter un Geteur sur le vecteur de noeud et chaque noeud
	const pNodeArray& GetNodes() const { return m_apNodes; }
	CNode::pNode GetFirstNode() const { return m_apNodes[0]; }
	CNode::pNode GetSecondNode() const { return m_apNodes[1]; }
	
protected:
	// TP 4 : modification du poids en  size_t
	size_t m_dWeight;   // poids de l'ar�te
	pNodeArray m_apNodes; // Vecteur de 2 noeuds

	// TP 4 :
	// TODO : ajouter une donn�e membre de type size_t correspondant au flux actuel passant par l ar�te
	size_t m_flux = 0;

public:
	// TP 2 :
// TODO : ajouter des Geteurs sur le milieu de l'ar�te et sur le poids
	float GetMilieuX()const { return (m_apNodes[0]->GetX() + m_apNodes[1]->GetX()) / 2; }
	float GetMilieuY()const { return (m_apNodes[0]->GetY() + m_apNodes[1]->GetY()) / 2; }
	size_t GetWeight() const { return m_dWeight; }

	// TODO : ajouter l'operateur d �galit� entre 2 ar�tes
	bool operator==(const CEdge& edge) { return m_dWeight == edge.m_dWeight && m_apNodes[0] == edge.m_apNodes[0] && m_apNodes[1] == edge.m_apNodes[1]; }

	// TP 4 :
	// TODO : ajouter un Geteur et un additionneur et un soustracteur sur le flux actuel
	size_t GetFlux()const { return m_flux; } // A MODIFIER
	void AddFlux(size_t n) { if (m_flux + n <= m_dWeight) { m_flux += n; } } // A FAIRE
	void SubFlux(size_t n) { if (m_flux - n >= 0 ) { m_flux -= n; } } // A FAIRE
};