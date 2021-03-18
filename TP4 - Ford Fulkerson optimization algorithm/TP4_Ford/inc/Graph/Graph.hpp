#pragma once

#include "Edge.hpp"
#include "Node.hpp"

#include <LibGraph2.h>

#include <memory>
#include <vector>
#include <set>
#include <climits>
#include <algorithm> // std::sort
#include <list>
#include <utility>

class CGraph{

public:
	using pNodeSet = std::set<CNode::pNode>; // Alias sur un vecteur de noeud
	using pEdgeSet = std::set<CEdge::pEdge>; // Alias sur un vecteur d'arêtes
	// TP 3 : On rajoute un alias sur un vecteur de pNode
	using  pNodeVector = std::vector<CNode::pNode>; // Alias sur un vecteur de noeud
	// TP 4 : 
	// TODO : ajouter 2 données membres représentant des pointeurs sur le noeud de départ et le noeud d arrivée
	//      : initialisés à nullptr
	CNode::pNode m_pNodeStart = nullptr;
	CNode::pNode m_pNodeEnd = nullptr;
	// TP 4 : 
	// TODO : ajouter une donnée membre de type booléen pour indiquer si le graphe est orienté
	//      : par défaut le graphe n est pas orienté mais pour ce TP il faut le rendre orienté (i.e. true)
	bool m_bOriented = false;
	// TP 4 : 
	// TODO : Ajout d'un alias : une chaine c'est une liste de sommet
	using Chaine = std::list<CNode::pNode>; // Alias sur une liste de noeuds (une chaine)
protected:

	pEdgeSet m_spEdges;
	pNodeSet m_spNodes;

public:
	CGraph() {};

	// TP 1 :
	// TODO : ajouter des Geteur sur les noeuds et arêtes ainsi que leur nombre d'éléments
	std::size_t GetNumberOfEdges() const { return m_spEdges.size(); }
	std::size_t GetNumberOfNodes() const { return m_spNodes.size(); }
	const pNodeSet& GetNodes() const { return m_spNodes; }
	const pEdgeSet& GetEdges() const { return m_spEdges; }

	// TP 1 :
	// TODO : ajouter une fonction qui ajoute un noeud
	void AddNewNode(CNode::pNode pNode) { m_spNodes.insert(pNode); }

	// TP 1 :
	// TODO : ajouter une fonction qui ajoute une arête 
	//         Attention de vérifier que les 2 noeuds existe dans le graphe
	void AddNewEdge(CEdge::pEdge pEdge) {
		for (auto& pNode : pEdge->GetNodes())
			if (m_spNodes.count(pNode) == 0) // si cette arête référence un sommet non existant dans ce graphe
				return; // idéalement, un throw. 
		m_spEdges.insert(pEdge);
	}

	// TP 1 :
	// TODO : ajouter une fonction qui enleve une arête 
	void RemoveEdge(CEdge::pEdge pEdge) {
		// On cherche l'arete dans le set d arete
		auto itpEdge = std::find(m_spEdges.begin(), m_spEdges.end(), pEdge);
		if (itpEdge != m_spEdges.end())
			m_spEdges.erase(itpEdge);
		// else warning dans la console ?
	}

	// TP 1 :
	// TODO : ajouter une fonction qui enleve un noeud
	//      : ATTENTION c'est la fonction la plus complexe :
	// il faut d'abord chercher toutes les arêtes qui touchent ce noeud
	// puis il faut enlever ces arêtes
	// enfin on enlève le noeud
	void RemoveNode(CNode::pNode pNode) {
		// On cherche le noeud dans le set de noeud
		auto itpNode = std::find(m_spNodes.begin(), m_spNodes.end(), pNode);
		// Si ce noeud existe
		if (itpNode != m_spNodes.end()) {
			// On enleve toutes les aretes touchant ce noeud
			for (auto itpEdge = m_spEdges.begin(); itpEdge != m_spEdges.end();/* RIEN */ ){
				if ((*itpEdge)->GetFirstNode() == (*itpNode) || (*itpEdge)->GetSecondNode() == (*itpNode))
					itpEdge = m_spEdges.erase(itpEdge);
				else
					itpEdge++;
			}
			// on enleve le noeud car il ne touche plus d arete
			m_spNodes.erase(itpNode);
		}
	}

	// TP 1 :
	// TODO :
	// Retourne le pointeur sur le noeud ayant le même nom ou nullptr si pas trouvé
	CNode::pNode GetNodeFromName(const std::string& name) const {
		// On parcourt le set de noeud et on renvoie celui qui a le bon nom
		for (auto& pNode : m_spNodes)
			if (pNode->GetName() == name)
				return pNode;
		// si non trouvé :
		return CNode::pNode(nullptr);
	}

	// TP 1 :
	// TODO : Remet le graphe à zéro 
	void Clear() { m_spEdges.clear(); m_spNodes.clear(); }

	// TP 1 :
	// TODO : efface toutes les arêtes 
	void ClearEdges() { m_spEdges.clear(); }

	// TP 2 :
	// TODO : parcourir toutes les arêtes pour compter combien de fois le noeud apparait
	std::size_t GetNodeDegree(CNode::pNode pNode) const {
		std::size_t countDegree = 0;
		// Pour chaque arete si elle touche le noeud on incremente le degre
		for (auto const& pEdge : m_spEdges) {
			if (pEdge->GetFirstNode() == pNode)
				++countDegree;
			if (pEdge->GetSecondNode() == pNode)
				++countDegree;
		}
		return countDegree;
	}

	// TP 2 :
	// TODO : On cherche le noeud le plus proche du point(x,y)
	// On initialise une distanceMin au max des float : FLT_MAX
	// Pour chaque noeud on calcule la distance euclienne (au carré) entre lui et le point(x,y)
	// Si cette distance est inferieure a la distance min
	//       On met a jour la nouvelle distance et le pointeur sur le noeud le plus proche
	const CNode::pNode GetNodeNear(unsigned int x, unsigned int y) const {
		float distMin = FLT_MAX; // max de distance 
		float dist; // distance du point aux parametres
		CNode::pNode pNodeNear = nullptr;
		for (auto const& pNode : m_spNodes) {// on cherche le noeud le plus proche du clic
			LibGraph2::CPoint node(pNode->GetX(), pNode->GetY());
			dist = (node.m_fX - x) * (node.m_fX - x) + (node.m_fY - y) * (node.m_fY - y);
			if (dist < distMin) {
				distMin = dist;
				pNodeNear = pNode;
			}
		}
		return pNodeNear;
	}

	// TP 2 :
	// TODO : On cherche l arete la plus proche du point(x,y)
// On initialise une distanceMin au max des float : FLT_MAX
// Pour chaque arete on calcule la distance euclienne entre le milieu de l arete et le point(x,y)
// Si cette distance est inferieure a la distance min
//       On met a jour la nouvelle distance et le pointeur sur l arete la plus proche
	const CEdge::pEdge GetEdgeNear(unsigned int x, unsigned int y) const {
		float distMin = FLT_MAX; // max de distance 
		float dist; // distance du point aux parametres
		CEdge::pEdge pEdgeNear = nullptr;
		for (auto const& pEdge : m_spEdges) { // On cherche le milieu de l'arete le plus proche du clic
			LibGraph2::CPoint milieu(pEdge->GetMilieuX(), pEdge->GetMilieuY());
			dist = (milieu.m_fX - x) * (milieu.m_fX - x) + (milieu.m_fY - y) * (milieu.m_fY - y);
			if (dist < distMin) {
				distMin = dist;
				pEdgeNear = pEdge;
			}
		}
		return pEdgeNear;
	}

	// TP 3 :
	// TODO : renvoie vrai si les 2 noeuds passés en paramêtre sont voisins
	bool CheckNodesAreNeighbors(CNode::pNode pNode1, CNode::pNode pNode2) const {
		for (auto const& pEdge : m_spEdges)
			if ((pEdge->GetFirstNode() == pNode1 && pEdge->GetSecondNode() == pNode2) || (pEdge->GetFirstNode() == pNode2 && pEdge->GetSecondNode() == pNode1))
				return true;
		return false;
	}


	// TP 4 : 
	// TODO : Rajouter les 2 accesseurs : 1 sur le noeud de départ et 1 sur le noeud d arrivée
	CNode::pNode GetNodeStart()const { return m_pNodeStart; }
	CNode::pNode GetNodeEnd()const { return m_pNodeEnd; }
	// TP 4 :
	// TODO : Mettre le noeud de départ en vert (color = 1) et le noeud d arrivée en rouge (color =0)
	void SetNodeStart(CNode::pNode pNode) { m_pNodeStart = pNode; m_pNodeStart->SetColor(1); }
	void SetNodeEnd(CNode::pNode pNode) { m_pNodeEnd = pNode; m_pNodeEnd->SetColor(0); }

	// TP 4 :
	// TODO : fonction permettant de savoir si le graphe est orienté
	bool IsOriented()const { return m_bOriented; }

	// TP 4 :
	// TODO : fonction permettant de changer l'orientation du graphe
	void SetOrientation(bool orientation) { m_bOriented = orientation; }

	// TP 4 :
	// TODO : retourne le flux entrant du sommet d arrivée
	//      : Si le sommet d'arrivée a été défini On récupère la liste des arêtes qui finissent sur le sommet d'arrivée
	//      : Vous pouvez utiliser GetEdgesIn et vous ajouter tous les flux de ces arêtes
	size_t MaxFlux() const
	{
		if (m_pNodeEnd != nullptr)
		{
			size_t res = 0;
			for (CEdge::pEdge iEdge : GetEdgesIn(m_pNodeEnd))
			{
				res += iEdge->GetFlux();
			}
			return res;
		}
	}

	// TP 4 :
	// TODO : fonction permettant de calculer le flux maximal arrivant sur le noeud d arrivée
	// A FAIRE EN DERNIER
	// TP 4 : OptimisationFF
	// TODO : Attention ceci est la fonction la plus difficile à faire en dernier !!!!
	// On parcourt la liste des chaines commencant par le noeud de départ et finissant par le noeud d'arrivée
	// Pour chaque chaine on parcourt la liste des aretes avec leur orientation
	//                         ET on cherche si c'est une chaine améliorante (le minimum de flux de chaque arête est > 0 (strictement)
	//                         SI elle améliore on ajoute ce fluxAmeliorant aux arêtes dans le bon sens (true)
	//                                          on enlève ce fluxAmeliorant aux arêtes dans le mauvais sens (false)

	void OptimisationFF(CNode::pNode nodeStart, CNode::pNode nodeEnd)
	{
		//Initialisation
		GetNodeStart()->SetColor(-1);
		GetNodeEnd()->SetColor(-1);
		for (CEdge::pEdge iEdge : m_spEdges)
		{
			iEdge->SubFlux(iEdge->GetFlux());
		}
		SetNodeStart(nodeStart);
		SetNodeEnd(nodeEnd);

		std::list<CGraph::Chaine> AllChaine = GetAllChaine(m_pNodeStart, m_pNodeEnd);
		
		for (CGraph::Chaine Chaine : AllChaine)
		{
			std::list<std::pair<CEdge::pEdge, bool>> ListeEdges = GetListeEdgesFromChaine(Chaine);
			size_t minimum = ListeEdges.begin()->first->GetWeight() - ListeEdges.begin()->first->GetFlux();
			for (std::pair<CEdge::pEdge, bool> iEdgePair : ListeEdges)
			{
				size_t iEdgePairWeight = iEdgePair.first->GetWeight();
				if (iEdgePairWeight < minimum)
				{
					minimum =iEdgePair.first->GetWeight() - iEdgePair.first->GetFlux();
				}
			}
			for (std::pair<CEdge::pEdge, bool> iEdgePair : ListeEdges)
			{
				if (iEdgePair.second == true)
				{
					iEdgePair.first->AddFlux(minimum);
				}
				else
				{
					iEdgePair.first->SubFlux(minimum);
				}
			}
		}
	}
	
protected : 

	// Fonctions privées 

	// TP 4 :
	// TODO : Renvoie l'arête formée par les 2 noeuds ainsi que son sens
	std::pair<CEdge::pEdge, bool> GetEdgeFromNodes(CNode::pNode pNode1, CNode::pNode pNode2)const
	{
		for (auto iEdge : m_spEdges)
		{
			if (iEdge->GetFirstNode() == pNode1)
			{
				if (iEdge->GetSecondNode() == pNode2)
				{
					std::pair<CEdge::pEdge, bool> pEdgeRetour = std::make_pair(iEdge, true);
					return pEdgeRetour;
				}
			}
			else if (iEdge->GetFirstNode() == pNode2)
			{
				if (iEdge->GetSecondNode() == pNode1)
				{
					std::pair<CEdge::pEdge, bool> pEdgeRetour = std::make_pair(iEdge, false);
					return pEdgeRetour;
				}
			}
		}
	}

	// TP 4 :
	// TODO : On renverra à la fois les arêtes et leur sens de parcours à partir d'une chaine
	//      : On commence par le premier noeud de la chaine
	//      : tant qu'on est pas arrivé au dernier noeud de la chaine
	//      :       on récupere le 2em point de l arête
	//      :           on récupère l'arête avec son sens
	//	    :             on l ajoute 
	//      :             notre point d arrivée devient le point de départ de la prochaine arrête
	std::list<std::pair<CEdge::pEdge, bool>> GetListeEdgesFromChaine(Chaine chaine) const
	{
		std::list<std::pair<CEdge::pEdge, bool>> listeEdges;

		std::list<CNode::pNode>::iterator CurrentNode = chaine.begin();
		std::list<CNode::pNode>::iterator NextNode = std::next(CurrentNode);
		while (NextNode != chaine.end())
		{
			listeEdges.push_back(GetEdgeFromNodes(*CurrentNode, *NextNode));
			CurrentNode = NextNode;
			NextNode = std::next(CurrentNode);
		}
		return listeEdges;
	}

	// TP 4 :
	// TODO : On renverra la liste de toutes les chaines possible partant du départ et arrivant à l'arrivée !!!!
	std::list<CGraph::Chaine> GetAllChaine(CNode::pNode pNodeStart, CNode::pNode pNodeEnd) const
	{
		auto pNode = pNodeStart;
		std::list<CGraph::Chaine> listeChaineFinale;
		std::list<CGraph::Chaine> listeChaine;
		CNode::pNode pNodeNext = nullptr;
		CGraph::Chaine uneChaine;
		uneChaine.push_back(pNode);
		listeChaine.push_back(uneChaine);

		while (!listeChaine.empty()) {// Pour toutes les chaines on va essayer de les compléter
			auto chaine = listeChaine.back(); // on recupere la derniere chaine
			listeChaine.pop_back();
			pNode = chaine.back(); // On recupere le dernier sommet de la chaine
			if (pNode == pNodeEnd) // Cette chaine est arrivee
				listeChaineFinale.push_back(chaine);
			else {// Sinon on essaye de completer la chaine
				auto listeEdgesOut = GetEdgesOut(pNode); // On regarde les arêtes sortantes
				for (auto pEdges : listeEdgesOut) {
					pNodeNext = pEdges->GetSecondNode(); // Le potentiel noeud suivant est le second noeud de l arete
					if (!IsInChaine(pNodeNext, chaine)) {// On regarde si le noeud ne fait pas déjà partie de la chaine
						auto chaineAjout(chaine); // On cree une nouvelle chaine copie de la chaine actuelle et on enlève son dernier noeud
						chaineAjout.push_back(pNodeNext);
						listeChaine.push_back(chaineAjout);
					}
				}
				auto listeEdgesIn = GetEdgesIn(pNode); // On regarde les arêtes entrantes
				for (auto pEdges : listeEdgesIn) {
					pNodeNext = pEdges->GetFirstNode(); // Le potentiel noeud suivant est le premier noeud de l arete
					if (!IsInChaine(pNodeNext, chaine)) {// On regarde si le noeud ne fait pas déjà partie de la chaine
						auto chaineAjout(chaine); // On cree une nouvelle chaine copie de la chaine actuelle 
						chaineAjout.push_back(pNodeNext);
						listeChaine.push_back(chaineAjout);
					}
				}
			}
		}
		return listeChaineFinale;
	}

	// TP 4 : GetEdgesIn
	// TODO : Renvoie la liste de toutes les arêtes qui finissent en pNode
	std::list<CEdge::pEdge> GetEdgesIn(CNode::pNode pNode)const
	{
		std::list<CEdge::pEdge> lAreteF;
		for (auto iEdge : m_spEdges)
		{
			if (iEdge->GetSecondNode() == pNode)
			{
				lAreteF.push_back(iEdge);
			}
		}
		return lAreteF;
	}
	
	// TP 4 : GetEdgesOut
	// TODO : Renvoie la liste de toutes les arêtes qui partent de pNode
	std::list<CEdge::pEdge> GetEdgesOut(CNode::pNode pNode)const
	{
		std::list<CEdge::pEdge> lAreteP;
		for (auto iEdge : m_spEdges)
		{
			if (iEdge->GetFirstNode() == pNode)
			{
				lAreteP.push_back(iEdge);
			}
		}
		return lAreteP;
	}// A MODIFIER

	// TP 4 : IsInChaine
	// TODO : Renvoie vrai si le noeud appartient à la chaine et faux sinon
	bool IsInChaine(CNode::pNode pNode, Chaine chaine)const
	{
		return (std::find(std::begin(chaine), std::end(chaine), pNode) != std::end(chaine));
	}
};

