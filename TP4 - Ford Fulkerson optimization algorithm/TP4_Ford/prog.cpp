#include <LibGraph2.h>
#include "TP.hpp"

using namespace LibGraph2;
using namespace std;

size_t CNode::m_uiNbNodes = 0;

/*!
* \brief
* Point d'entrée principal de l'application.
* 
* \param hInstance     Non utilisé
* \param hPrevInstance Non utilisé
* \param lpCmdLine     Non utilisé
* \param nCmdShow      Non utilisé
* 
* \returns
* 0.
*/

// TP 4 : 
// TODO : Ajouter une étape à l'énumeration pour gérer le lancement de l'algorithme de Ford-Fulkenson
// Ensuite ajouter le cas qui va gérer la sélection du sommet de départ puis du sommet d'arrivée et enfin va lancer l'algo
// Je vous conseille de vous inspirer de la création d'une arête ( Elle aussi utilise 2 points !!!!)


int APIENTRY _tWinMain(HINSTANCE hInstance,	HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hInstance); UNREFERENCED_PARAMETER(hPrevInstance); UNREFERENCED_PARAMETER(lpCmdLine); UNREFERENCED_PARAMETER(nCmdShow);

#ifdef _DEBUG
	_CrtMemState mem1, mem2, memdiff;
#endif
	_CrtMemCheckpoint(&mem1);
	{
		ILibGraph2* pLibgraph = GetLibGraph2();
		pLibgraph->show();
		CTP tp;
		// Création du graphe d exemple
		tp.CreateExempleGraph();
		enum class Etape
		{
			Noop,
			AddNode,
			AddEdge,
			DeleteNode,
			DeleteEdge, // A COMPLETER ***************************  TP 4 ****************************************** 
			FordFulkerson
		};
		Etape etape = Etape::Noop;
		evt e;
		bool point1Select = false;
		CNode::pNode pPoint1;
		CEdge::pEdge pEdge1;
		while (pLibgraph->waitForEvent(e)) {
			switch (e.type) {
			case evtRefresh:
				pLibgraph->beginPaint();
					tp.Draw();
				pLibgraph->endPaint();
				break;
			case evtKeyDown:
				switch (e.vkKeyCode)
				{
				case 'N':
					if (etape == Etape::AddNode)
						etape = Etape::Noop;
					else
						etape = Etape::AddNode;
					break;
				case 'E':
					if (etape == Etape::AddEdge)
						etape = Etape::Noop;
					else
						etape = Etape::AddEdge;
					break;
				case 'D':
					if (etape == Etape::DeleteNode)
						etape = Etape::Noop;
					else
						etape = Etape::DeleteNode;
					break;
				case 'Z':
					if (etape == Etape::DeleteEdge)
						etape = Etape::Noop;
					else
						etape = Etape::DeleteEdge;
					break;
				case 'K':
					tp.CreateGraphFull();
					etape = Etape::Noop;
					pLibgraph->askForRefresh();
					break;
	// A MODIFIER                        ***************************  TP 4 ****************************************** 
				case 'F':
					if (etape == Etape::FordFulkerson)
						etape = Etape::Noop;
					else
						etape = Etape::FordFulkerson;
					break;
				}
				break;
			case evtMouseDown:
				switch (etape) {
					case Etape::AddNode: {
						tp.AddNode(e.x, e.y);
						pLibgraph->askForRefresh();
						break;
					}
					case Etape::AddEdge: {
						// TP 3 : TODO
						// C'est ici qu'on ajoute une arête
						if (!point1Select) {
							pPoint1 = tp.GetGraph().GetNodeNear(e.x, e.y);
							point1Select = true;
						}
						else {
							tp.AddEdge(pPoint1, tp.GetGraph().GetNodeNear(e.x, e.y));
							point1Select = false;
						}
						pLibgraph->askForRefresh();
						break;
					}
					case Etape::DeleteNode:	{
						pPoint1 = tp.GetGraph().GetNodeNear(e.x, e.y);
						tp.DeleteNode(pPoint1);
						pLibgraph->askForRefresh();
						break;
					}
					case Etape::DeleteEdge:	{
						pEdge1 = tp.GetGraph().GetEdgeNear(e.x, e.y);
						tp.DeleteEdge(pEdge1);
						pLibgraph->askForRefresh();
						break;
					}
			// A MODIFIER                       ***************************  TP 4 ****************************************** 
					case Etape::FordFulkerson: {
						if (!point1Select) {
							pPoint1 = tp.GetGraph().GetNodeNear(e.x, e.y);
							point1Select = true;
						}
						else {
							tp.GetGraph().OptimisationFF(pPoint1, tp.GetGraph().GetNodeNear(e.x, e.y));
							point1Select = false;
						}
						pLibgraph->askForRefresh();
						break;
					}
				}
				break;
			}
		}
		ReleaseLibGraph2();
	}
	_CrtMemCheckpoint(&mem2);
	if (_CrtMemDifference(&memdiff, &mem1, &mem2))
	{
		_CrtMemDumpAllObjectsSince(&mem1);
		GetLibGraph2()->guiMessageBox("Fuites mémoires !", "Des fuites mémoires ont été détectées, vérifiez vos allocations et désallocations !", MsgBtnOK, MsgIcnStop);
		ReleaseLibGraph2();
	}
	return 0;
}
