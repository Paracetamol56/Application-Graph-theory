/*!
 * \file  "TP.h"
 *
 * \brief Déclaration de la classe CTP. 
 *
 */
#pragma once
#include "Graph/Graph.hpp"
#include "Graph/Edge.hpp"
#include "Graph/Node.hpp"
#include <LibGraph2.h>

#include <cstdlib>
#include <ctime>

#include <sstream>
#include <iomanip>
#include <random>

/*!
 * \brief
 * Classe de gestion du TP.
 * 
 * Cette classe est instanciée une seule fois pour répresenter toutes les actions du TP.
 * 
 * \todo 
 
 */
using namespace LibGraph2;
class CTP
{
	//!\brief graphe
	CGraph m_graph;
	//!\brief fonction affichage de noeud
	void DrawNode(CNode::pNode pNode)
	{
		ILibGraph2* pLibgraph = GetLibGraph2();
		CRectangle rect(CPoint(pNode->GetX(), pNode->GetY()), CSize(26, 26));
		pLibgraph->setPen(MakeARGB(255, 100, 122, 153), 1.0f);

		enum Color {
			Red, Green
		};

		switch (pNode->GetColor()) {
		case Red:
			pLibgraph->setSolidBrush(MakeARGB(255, 255, 0, 0));
			break;
		case Green:
			pLibgraph->setSolidBrush(MakeARGB(255, 0, 255, 0));
			break;
		default:
			pLibgraph->setSolidBrush(MakeARGB(30, 30, 30, 153));
			break;
		}
		pLibgraph->drawEllipse(rect);
		pLibgraph->setSolidBrush(MakeARGB(255, 0, 0, 0));
		CPoint namePosition(rect.m_ptTopLeft);
		namePosition.m_fX += 1;
		namePosition.m_fY += 6;
		pLibgraph->drawString(pNode->GetName(), namePosition);
	}

	//!\brief fonction affichage d arrête
	// TP4  :
	// TODO : ATTENTION on rajoute les pointes des flèches
	void DrawEdge(CEdge::pEdge pEdge) {
		ILibGraph2* pLibgraph = GetLibGraph2();
		pLibgraph->setPen(MakeARGB(255, 255, 100, 100), 2.0f);

		CNode::pNode pPoint1 = pEdge->GetFirstNode();
		CNode::pNode pPoint2 = pEdge->GetSecondNode();
		CPoint p1(pPoint1->GetX() + 13, pPoint1->GetY() + 13);
		CPoint p2(pPoint2->GetX() + 13, pPoint2->GetY() + 13);
		CPoint weightPosition;
		if (*pPoint1 == pPoint2) { // si meme sommets on dessine une ellipse
			CRectangle rect(CPoint(p1.m_fX - 45, p1.m_fY - 45), CSize(50, 50));
			pLibgraph->setSolidBrush(MakeARGB(0, 0, 0, 0)); // pas d intérieur à l ellipse
			pLibgraph->drawArc(rect, 52, 344);
			weightPosition = CPoint(p1.m_fX - 55, p1.m_fY - 55);
		}
		else {
			weightPosition = CPoint((p1.m_fX + p2.m_fX) / 2, (p1.m_fY + p2.m_fY) / 2);
			pLibgraph->drawLine(p1, p2);
			// Si le graphe est orienté on dessine la fleche sur P2 (2 petits segments)
			if (m_graph.IsOriented()) {
				CPoint P1P2(p2.m_fX - p1.m_fX, p2.m_fY - p1.m_fY); // Pour avoir la direction de P1P2
				float norme = sqrt(P1P2.m_fX * P1P2.m_fX + P1P2.m_fY * P1P2.m_fY); // On normalise
				P1P2.m_fX /= norme;
				P1P2.m_fY /= norme;
				CPoint Ortho(-P1P2.m_fY, P1P2.m_fX); // On cherche l orthogonal direct a P1P2
				CPoint Fleche(p2.m_fX - 30 * P1P2.m_fX, p2.m_fY - 30 * P1P2.m_fY); // On se pose a la base de la fleche
				CPoint P0(Fleche.m_fX + 10 * Ortho.m_fX, Fleche.m_fY + 10 * Ortho.m_fY); // extremite nord de la fleche
				CPoint P3(Fleche.m_fX - 10 * Ortho.m_fX, Fleche.m_fY - 10 * Ortho.m_fY); // extremite sud de la fleche
				pLibgraph->setPen(MakeARGB(190, 200, 150, 100), 1.5f);
				pLibgraph->drawLine(P0, p2);
				pLibgraph->drawLine(P3, p2);
			}
		}
		pLibgraph->setSolidBrush(MakeARGB(255, 0, 0, 0));
		std::ostringstream os;
		os << std::setprecision(3) << pEdge->GetFlux() << "/" << pEdge->GetWeight();
		pLibgraph->drawString(os.str(), weightPosition);
	}
	//Fin Solution
public:
	CTP(void) { } // constructeur fait un graph vide par défaut

	CGraph& GetGraph() { return m_graph; }


	void Draw() {// Affiche les noeuds et les arêtes 
		ILibGraph2* pLibgraph = GetLibGraph2();
		//Affiche les Arêtes
		for (auto const& pedge : m_graph.GetEdges())
			DrawEdge(pedge);
		//Affiche les Noeuds
		for (auto const& pnode : m_graph.GetNodes())
			DrawNode(pnode);
		pLibgraph->drawString(std::to_string(m_graph.MaxFlux()), CPoint{10, 10});
	}

	// TP4  :
	// TODO : renvoyer l arête créée
	CEdge::pEdge AddEdge(CNode::pNode p1, CNode::pNode p2) {
		std::random_device rd;
		std::default_random_engine gen(rd());
		size_t weight = std::uniform_int_distribution<>{ 1, 9 }(gen);
		CEdge::pEdge pEdge = CEdge::New(p1, p2, weight);
		m_graph.AddNewEdge(pEdge);
		return pEdge;
	}

	// TP4  : AddEdge avec un paramètre en plus de type size_t
	// TODO : renvoyer l arête créée
	CEdge::pEdge AddEdge(CNode::pNode p1, CNode::pNode p2, size_t weight) {
		CEdge::pEdge pEdge = CEdge::New(p1, p2, weight);
		m_graph.AddNewEdge(pEdge);
		return pEdge;
	}

	// TP4  :
	// TODO : renvoyer le noeud créé
	CNode::pNode AddNode(unsigned int x, unsigned int y) {
		std::string nameNode{ "P" };
		CNode::pNode pNode = CNode::New(nameNode);
		nameNode += std::to_string(pNode->GetNbNodes());
		pNode->SetName(nameNode);
		pNode->SetX(float(x));
		pNode->SetY(float(y));
		m_graph.AddNewNode(pNode);
		return pNode;
	}

	void DeleteNode(CNode::pNode p) { m_graph.RemoveNode(p); }
	
	void DeleteEdge(CEdge::pEdge p) { m_graph.RemoveEdge(p); }
	
	// TP 3 : 
	// TODO : ajouter une fonction qui crée un graphe complet à partir des noeuds du graphe
	void CreateGraphFull() {
		if (m_graph.GetNumberOfNodes() > 1) {
			m_graph.ClearEdges();
			for (auto const& pNode1 : m_graph.GetNodes())
				for (auto const& pNode2 : m_graph.GetNodes())
					if (pNode1 < pNode2)
						AddEdge(pNode1, pNode2);
		}
	}


	// TP4
	void CreateExempleGraph() {
		m_graph.SetOrientation(true);
		auto pNode1 = AddNode(200, 250);
		auto pNode2 = AddNode(400, 450);
		auto pNode3 = AddNode(500, 50);
		auto pNode4 = AddNode(700, 350);
		auto pNode5 = AddNode(900, 150);
		AddEdge(pNode1, pNode2, 4);
		AddEdge(pNode1, pNode3, 3);
		AddEdge(pNode1, pNode5, 2);
		AddEdge(pNode2, pNode3, 1);
		AddEdge(pNode2, pNode4, 2);
		AddEdge(pNode3, pNode5, 5);
		AddEdge(pNode4, pNode5, 1);
		m_graph.SetNodeStart(pNode1);
		m_graph.SetNodeEnd(pNode5);
	}


};