/*!
 * \file  "TP.hpp"
 *
 * \brief Déclaration de la classe CTP. 
 *
 */
#pragma once
#include "Graph/Graph.hpp"
#include "Graph/Edge.hpp"
#include "Graph/Node.hpp"
#include<LibGraph2.h>

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

	  enum Color
	  {
		  Red, Green, Blue, Yellow, Cyan, Magenta, Brown,  Salmon, Chocolate, Orange, Tan, Gold, Olive, Chartreuse, Teal, RoyalBlue, Indigo, Turquoise, Purple, Violet, Crimson

	  };

	  //switch (pNode->GetColor())
	  //{
	  //case Red:
		 // pLibgraph->setSolidBrush(MakeARGB(255, 255, 0, 0));
		 // break;
	  //case Olive:
		 // pLibgraph->setSolidBrush(MakeARGB(255, 128, 128, 0));
		 // break;
	  //case Yellow:
		 // pLibgraph->setSolidBrush(MakeARGB(255, 255, 255, 0));
		 // break;
	  //case Blue:
		 // pLibgraph->setSolidBrush(MakeARGB(255, 0, 0, 255));
		 // break;
	  //case Brown:
		 // pLibgraph->setSolidBrush(MakeARGB(255, 165, 42, 42));
		 // break;
	  //case Chocolate:
		 // pLibgraph->setSolidBrush(MakeARGB(255, 210, 105, 30));
		 // break;
	  //case Orange:
		 // pLibgraph->setSolidBrush(MakeARGB(255, 255, 165, 0));
		 // break;
	  //case Tan:
		 // pLibgraph->setSolidBrush(MakeARGB(255, 210, 180, 140));
		 // break;
	  //case Gold:
		 // pLibgraph->setSolidBrush(MakeARGB(255, 255, 215, 0));
		 // break;
	  //case Chartreuse:
		 // pLibgraph->setSolidBrush(MakeARGB(255, 127, 255, 0));
		 // break;
	  //case Green:
		 // pLibgraph->setSolidBrush(MakeARGB(255, 0, 255, 0));
		 // break;
	  //case Turquoise:
		 // pLibgraph->setSolidBrush(MakeARGB(255, 64, 224, 208));
		 // break;
	  //case Teal:
		 // pLibgraph->setSolidBrush(MakeARGB(255, 0, 128, 128));
		 // break;
	  //case Salmon:
		 // pLibgraph->setSolidBrush(MakeARGB(255, 250, 128, 114));
		 // break;
	  //case Cyan:
		 // pLibgraph->setSolidBrush(MakeARGB(255, 0, 255, 255));
		 // break;
	  //case RoyalBlue:
		 // pLibgraph->setSolidBrush(MakeARGB(255, 65, 105, 225));
		 // break;
	  //case Indigo:
		 // pLibgraph->setSolidBrush(MakeARGB(255, 75, 0, 130));
		 // break;
	  //case Purple:
		 // pLibgraph->setSolidBrush(MakeARGB(255, 128, 0, 128));
		 // break;
	  //case Magenta:
		 // pLibgraph->setSolidBrush(MakeARGB(255, 255, 0, 255));
		 // break;
	  //case Violet:
		 // pLibgraph->setSolidBrush(MakeARGB(255, 238, 130, 238));
		 // break;
	  //case Crimson:
		 // pLibgraph->setSolidBrush(MakeARGB(255, 220, 20, 60));
		 // break;
	  //default:
		  pLibgraph->setSolidBrush(MakeARGB(30, 30, 30, 153));
		 // break;
	  //}
	  pLibgraph->drawEllipse(rect);
	  pLibgraph->setSolidBrush(MakeARGB(255, 0, 0, 0));
	  CPoint namePosition(rect.m_ptTopLeft);
	  namePosition.m_fX += 1;
	  namePosition.m_fY += 6;
	  pLibgraph->drawString(pNode->GetName(), namePosition);
  }
  //!\brief fonction affichage d arrête
  void DrawEdge(CEdge::pEdge pEdge)
  {
	  ILibGraph2* pLibgraph = GetLibGraph2();
	  pLibgraph->setPen(MakeARGB(255, 255, 100, 100), 2.0f);

	  CNode::pNode pPoint1 = pEdge->GetFirstNode();
	  CNode::pNode pPoint2 = pEdge->GetSecondNode();
	  CPoint p1(pPoint1->GetX() + 13, pPoint1->GetY() + 13);
	  CPoint p2(pPoint2->GetX() + 13, pPoint2->GetY() + 13);
	  pLibgraph->drawLine(p1, p2);
	  CPoint weightPosition;
	  if (*pPoint1 == pPoint2) // si meme sommets on dessine une ellipse
	  {
		  CRectangle rect(CPoint(p1.m_fX - 45, p1.m_fY - 45), CSize(50, 50));
		  pLibgraph->setSolidBrush(MakeARGB(0, 0, 0, 0)); // pas d intérieur à l ellipse
		  pLibgraph->drawArc(rect, 52, 344);
		  weightPosition = CPoint(p1.m_fX - 55, p1.m_fY - 55);
	  }
	  else
	  {
		  weightPosition = CPoint((p1.m_fX + p2.m_fX) / 2, (p1.m_fY + p2.m_fY) / 2);
	  }
	  pLibgraph->setSolidBrush(MakeARGB(255, 0, 0, 0));
	  std::ostringstream os;
	//  os << std::setprecision(3) << pEdge->GetWeight();
	  pLibgraph->drawString(os.str(), weightPosition);
  }
  //Fin Solution
public:
	CTP(void) { } // constructeur fait un graph vide par défaut
	const CGraph & GetGraph()const { return m_graph; }
	void Draw() // Affiche les noeuds et les arêtes 
	{
		ILibGraph2* pLibgraph = GetLibGraph2();
		//Affiche les Arêtes
		for (auto const & pedge : m_graph.GetEdges())
			DrawEdge(pedge);
		//Affiche les Noeuds
		for (auto const & pnode : m_graph.GetNodes())
			DrawNode(pnode);
	}
	void AddEdge(CNode::pNode p1, CNode::pNode p2)
	{
		std::random_device rd;
		std::default_random_engine gen(rd());
		float weight = float(std::uniform_real_distribution<>{ 0, 100 }(gen));
		m_graph.AddNewEdge(CEdge::New(p1, p2, weight));
	}
	void AddNode(unsigned int x, unsigned int y)
	{
		CNode::pNode pNode = std::make_shared<CNode>();
		std::string nameNode{ "P" };
		nameNode += std::to_string(pNode->GetNbNodes());
		pNode->SetName(nameNode);
		pNode->SetX(float(x));
		pNode->SetY(float(y));
		m_graph.AddNewNode(pNode);
	}
	void DeleteNode(CNode::pNode p) { m_graph.RemoveNode(p); }
	void DeleteEdge(CEdge::pEdge p) { m_graph.RemoveEdge(p); }
	
	// TP 2 : TODO ajouter une fonction qui crée un graphe complet à partir des noeuds du graphe
	void CreateGraphFull()
	{
		m_graph.ClearEdges();
		for (CNode::pNode i : m_graph.GetNodes())
		{
			for (CNode::pNode j : m_graph.GetNodes())
			{
				if (i != j)
				{
					AddEdge(i, j);
				}
			}
		}
	}
};

