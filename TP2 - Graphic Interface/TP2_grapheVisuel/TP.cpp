/*!
 * \file  "TP.cpp"
 *
 * \brief Définition de la classe CTP. 
 *
 */

#define _USE_MATH_DEFINES
//#include <sstream>
#include <LibGraph2.h>

#include "TP.hpp"


using namespace LibGraph2;
using namespace std;

void CTP::DrawNode(CNode::pNode p)


void CTP::DrawEdge(CEdge::Pointer p)
{
	ILibGraph2* pLibgraph = GetLibGraph2();
	pLibgraph->setPen(MakeARGB(255, 255, 100, 100), 2.0f);

	CNode::Pointer pPoint1 = p->GetFirstNode();
	CNode::Pointer pPoint2 = p->GetSecondNode();
	CPoint p1(pPoint1->GetX() + 13, pPoint1->GetY() + 13);
	CPoint p2(pPoint2->GetX() + 13, pPoint2->GetY() + 13);
	pLibgraph->drawLine(p1,p2);
	CPoint weightPosition;
	if ( *pPoint1 == *pPoint2) // si meme sommets on dessine une ellipse
	{
		CRectangle rect(CPoint(p1.m_fX - 45, p1.m_fY - 45), CSize(50, 50));
		pLibgraph->setSolidBrush(MakeARGB(0, 0, 0, 0)); // pas d intérieur à l ellipse
		pLibgraph->drawArc(rect, 52, 344);
		weightPosition= CPoint(p1.m_fX-55 , p1.m_fY -55);
	}
	else
	{
		weightPosition=CPoint((p1.m_fX + p2.m_fX) / 2, (p1.m_fY + p2.m_fY) / 2);
	}
		pLibgraph->setSolidBrush(MakeARGB(255, 0, 0, 0));
		ostringstream os;
		os << setprecision(3) << p->GetWeight();
		pLibgraph->drawString(os.str(), weightPosition);
}


/*!
 * \brief
 * Affiche le contenu de la fenêtre.
 */
void CTP::Draw()
{
	ILibGraph2* pLibgraph = GetLibGraph2();

	//Affiche les Noeuds
	for (auto it : m_graph.GetNodes())
		DrawNode(it);

	//Affiche les Arêtes
	for (auto it : m_graph.GetEdges())
		DrawEdge(it);
}

void CTP::AddEdge(CNode::Pointer p1, CNode::Pointer p2)
{
	random_device rd;
	default_random_engine gen(rd());

	float weight = uniform_real_distribution<>{0, 100}(gen);
	
	m_graph.AddNewEdge(CEdge::New(p1, p2, weight));
}

void CTP::AddNode(unsigned int x, unsigned int y)
{
	CNode::Pointer pNode = make_shared<CNode> ();
	string nameNode{ "P" };
	nameNode += to_string(pNode->GetNbInstance());
	pNode->SetName(nameNode);
	pNode->SetX(x);
	pNode->SetY(y);
	m_graph.AddNewNode(pNode);
}

void CTP::DeleteNode(CNode::Pointer p)
{
	m_graph.RemoveNode(p);
}

void CTP::DeleteEdge(CEdge::Pointer p)
{
	m_graph.RemoveEdge(p);
}

void CTP::Colorate()
{
	m_graph.ColorByWelchPowell();
}


