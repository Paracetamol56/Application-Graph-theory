#include "Graph.hpp"
#include "test.hpp"
using std::cout;
int main(int argc, char* argv[])
{
	BEGIN_TESTS;

	CGraph g;

	NOTICE("Debut des tests.\n");
	cout << g;
	TEST("Aucun sommet : ", g.GetNumberOfNodes(), 0);
	TEST("Aucune arete : ", g.GetNumberOfEdges(), 0);

	CNode::pNode pNodeA = std::make_shared<CNode>("A");
	g.AddNewNode(pNodeA);
	cout << g;
	TEST("AddNewNode et GetNumberOfNodes : ", g.GetNumberOfNodes(), 1);
	TEST("AddNewNode et GetNumberOfEdges : Aucune arete : ", g.GetNumberOfEdges(), 0);

	CNode::pNode pNodeB = std::make_shared<CNode>("B");
	g.AddNewNode(pNodeB);
	cout << g;
	TEST("Deux sommets : ", g.GetNumberOfNodes(), 2);
	TEST("Aucune arete : ", g.GetNumberOfEdges(), 0);

	CEdge::pEdge pEdge1 = std::make_shared<CEdge>(pNodeA, pNodeB, 0);
	g.AddNewEdge(pEdge1);
	cout << g;
	TEST("AddNewEdge et GetNumberOfEdges : ", g.GetNumberOfEdges(), 1);

	CEdge::pEdge pEdge4 = std::make_shared<CEdge>(pNodeA, pNodeA, 5);
	g.AddNewEdge(pEdge4);
	cout << g;
	TEST("Deux sommets : ", g.GetNumberOfNodes(), 2);
	TEST("Deux aretes : ", g.GetNumberOfEdges(), 2);

	CNode::pNode pNodeC = std::make_shared<CNode>("C");
	CEdge::pEdge pEdge2 = std::make_shared<CEdge>(pNodeA, pNodeC, 1);
	CEdge::pEdge pEdge3 = std::make_shared<CEdge>(pNodeB, pNodeC, 2);
	g.AddNewNode(pNodeC);
	g.AddNewEdge(pEdge2);
	g.AddNewEdge(pEdge3);
	cout << g;
	TEST("Trois sommets : ", g.GetNumberOfNodes(), 3);
	TEST("Quatre aretes : ", g.GetNumberOfEdges(), 4);
	TEST("Degre d'un sommet avec boucle : ", g.GetNodeDegree(pNodeA), 4);
	TEST("Degre d'un sommet sans  boucle : ", g.GetNodeDegree(pNodeB), 2);

	g.RemoveEdge(pEdge4);
	cout << g;
	TEST("RemoveEdge : Trois sommets : ", g.GetNumberOfNodes(), 3);
	TEST("RemodeEdge : Trois aretes : ", g.GetNumberOfEdges(), 3);
	TEST("Degre d'un sommet sans  boucle : ", g.GetNodeDegree(pNodeA), 2);
	TEST("GetNodeFromRef : ", g.GetNodeFromReference(*pNodeC) == pNodeC, true);
	
	g.RemoveNode(pNodeC);
	cout << g;
	TEST("RemoveNode : GetNodeFromRef : ", g.GetNodeFromReference(*pNodeC) == nullptr, true);
	TEST("RemoveNode : Deux sommets : ", g.GetNumberOfNodes(), 2);
	TEST("RomoveNode : Deux aretes : ", g.GetNumberOfEdges(), 1);
	TEST("GetNode avec nom incorrect : ", g.GetNodeFromName("C"), nullptr);
	TEST("GetNode avec nom correct : ", g.GetNodeFromName("A"), pNodeA);

	END_TESTS;

	return 0;
}

