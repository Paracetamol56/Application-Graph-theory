#pragma once

#include <string>
#include <memory>

class CNode {

public:
	using pNode = std::shared_ptr<CNode>;

	// TP 2 : 
	// Fonction pour ajouter des noeuds
	static pNode New(const std::string& name = std::string()) { return std::make_shared<CNode>(name); }

	CNode(const std::string& name = std::string()) : m_sName(name) { m_uiNbNodes++; }

	const std::string& GetName() const { return m_sName; }
	void SetName(const std::string& name) { m_sName = name; }

protected : 
	std::string m_sName;
	// will later hold more infos

	// TP 2 : 
// TODO : Ajouter un attribut de type size_t pour gérer les degrés. 
// Par défaut, cet attribut doit être initialisé à 0 (pas d'arêtes).
// On ajoute aussi une variable statique m_nbNodes qui totalisera les instances 
// de CNode initialisée à 0 ( dans le prog.cpp !!!)
// Enfin on rajoutes 2 attributs pour gérer la position du point sur la fenêtre
// de type float
	size_t m_uiDegre = 0;
	static  size_t m_uiNbNodes;
	float m_fPosX = 0;
	float m_fPosY = 0;
	int m_nodeColor = -1;

public :
	// TP 2 : 
// TODO : Ajouter les accesseur sur le degré
// Ajouter des accesseurs sur le nombre d'instance de CNode
// Ajouter des accesseurs sur la position en x et en y des points
// Ajouter l'operateur == qui teste si 2 noeuds ont le même nom
	
	size_t GetNbNodes()const { return m_uiNbNodes; }
	size_t GetDegre()const { return m_uiDegre; }
	void AddDegre(size_t degreToAdd) { m_uiDegre += degreToAdd; }
	void SubDegre(size_t degreToSub) { m_uiDegre -= degreToSub; }
	float GetX()const { return m_fPosX; }
	float GetY()const { return m_fPosY; }
	void SetX(float X) { m_fPosX = X; }
	void SetY(float Y) { m_fPosY = Y; }
	bool operator==(const CNode& node) { return m_sName == node.m_sName; }
	bool operator==(const CNode::pNode& pNode) { return m_sName == pNode->m_sName; }
	int GetColor()const { return m_nodeColor; }
	void SetColor(int newColor) { m_nodeColor = newColor; }
};

// TP 2 :
// foncteur pour trier les noeuds en fonction du degré décroissant
struct ByDegre
{
	bool operator () (const CNode::pNode& lhs, const CNode::pNode& rhs)
	{
		return lhs->GetDegre() < rhs->GetDegre();
	}
};
