#pragma once

#include <string>
#include <memory>

class CNode {

public:
	using  pNode = std::shared_ptr<CNode> ; // Alias pour pointeur sur CNode
	
	static pNode New(const std::string& name = std::string()) { return std::make_shared<CNode>(name); }

	CNode(const std::string& name = std::string()) { SetName(name); m_uiNbNodes++; };

	// TP 1 :
	// TODO : ajouter un Geteur et un Seteur sur m_sName
	const std::string& GetName() const { return m_sName; }
	void SetName(const std::string& name) { m_sName = name; }

	// TODO : ajouter l'operateur == pour comparer 2 CNode 
	// Ajouter l'operateur == qui teste si 2 noeuds ont le même nom
	bool operator==(const CNode & node)const { return m_sName == node.m_sName; }
	bool operator==(const CNode::pNode& pNode) { return m_sName == pNode->m_sName; }

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
	// Par défaut, cet attribut doit être initialisé à 0.
	// TODO : Ajouter un attribut de type int pour gérer la coloration. 
	// Par défaut, cet attribut doit être initialisé à -1 (aucune couleur).
	size_t m_uiDegre = 0;
	static  size_t m_uiNbNodes;
	float m_fPosX = 0;
	float m_fPosY = 0;
	int m_iColor = -1;

public : 
	// TP 2 : 
	// TODO : Ajouter les accesseur sur le degré
	// Ajouter des accesseurs sur le nombre d'instance de CNode
	// Ajouter des accesseurs sur la position en x et en y des points
	// Ajouter un geteur sur le nombre d'instance de CNode

	size_t GetDegre()const { return m_uiDegre; }
	void AddDegre(size_t degreToAdd) { m_uiDegre += degreToAdd; }
	void SubDegre(size_t degreToSub) { m_uiDegre -= degreToSub; }
	int GetColor() const { return m_iColor; }
	void SetColor(int c) { m_iColor = c; }
	float GetX() const { return m_fPosX; }
	float GetY() const { return m_fPosY; }
	void SetX(float x) { m_fPosX = x; }
	void SetY(float y) { m_fPosY = y; }
	static size_t GetNbNodes() { return m_uiNbNodes; }
};