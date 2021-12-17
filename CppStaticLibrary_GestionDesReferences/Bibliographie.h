/** \file  Bibliographie.h
 * \brief ce fichier contient toute les declarations comprise dans la Classe Bibliographie
 * \author M4ST3R-Y0DA-44
 *
 * \date Created on 20 novembre 2021, 19:03
 */

#ifndef BIBLIOGRAPHIE_H
#define BIBLIOGRAPHIE_H

#include "Reference.h"
#include <string>
#include <vector>

/**\namespace biblio
 * \brief Un namespace qui contient la classe Reference, Ouvrage, Journal et Bibliographie ainsi que toute leur attributs et methodes*/
namespace biblio
{

  /** \class Bibliographie
   * \brief class qui contient le constructeur ainsi que les methodes de la classe Bibliographie */
  class Bibliographie
  {
  public:
    /** \fn Bibliographie(const std::string& p_nomDesBiblio)
     * \brief constructeur de la classe Bibliographie
     * \param p_nomDesBiblio (string) nom de la bibliographie que l'on creer*/
    Bibliographie (const std::string& p_nomDesBiblio);

    /** \fn const std::string reqNomDesBiblio () const
     * \brief fonction qui permet la lecture de l'attribut m_nomDesBiblio
     * \return (string) de l'attribut m_nomDesBiblio*/
    const std::string reqNomDesBiblio () const;

    /** \fn void ajouterReference (const Reference& p_nouvelleReference)
     * \brief fonction qui permet d'ajouter un pointeur de Reference dans le vecteur m_vReferences
     * \param p_nouvelleReference (Reference&) reference a ajouter*/
    void ajouterReference (const Reference& p_nouvelleReference);

    /** \fn void supprimerReference (const string& p_identifiant)
     *  \brief fonction qui supprime la Reference dont l'identifiant est recu en parametre.
     *  \param p_identifiant (string&) contenant le code ISSN/ISBN a supprimer.*/
    void supprimerReference (const std::string& p_identifiant);

    /** \fn const std::string reqBibliographieFormate ()
     * \brief fonction qui retourne une lecture formate de la liste du vecteur m_vReferences
     * \return (string) de la liste des References du vecteur m_vReferences sous une liste formate*/
    const std::string reqBibliographieFormate ();

    /** \fn ~Bibliographie()
     *  \brief destructeur de la classe Reference*/
    ~Bibliographie ();

    /** \fn Bibliographie* clone()
     *  \brief fonction qui clone l'objet Bibliographie
     *  \return (Bibliographie*) clone de la Bibliographie */
    Bibliographie* clone ();

    /** \fn const Bibliographie* operator= (const Bibliographie& p_biblio)
     *  \brief fonction de l'operateur d'assignation
     *  \param p_biblio (Bibliographie&) Bibliographie a assigne
     *  \return (Bibliographie*) la copie de p_biblio dans la Bibliographie cible*/
    const Bibliographie* operator= (Bibliographie& p_biblio);

  private:
    /** \fn void verifieInvariant() const
     * \brief methode qui verifie les invariants de la classe Bibliographie*/
    void verifieInvariant () const;

    /** \fn bool referenceEstDejaPresente (const biblio::Reference& p_reference) const
     * \brief fonction qui verifie si un identifiant (ISSN/ISBN) est deja present dans la liste de Bibliographie
     * \param p_reference (Reference&) reference a verifier si elle est contenue dans la bibliographie
     * \return (bool) vrai si la Reference est deja presente, faux sinon*/
    bool referenceEstDejaPresente (const biblio::Reference& p_reference);

    std::string m_nomDesBiblio; /*\brief (string) nom de la bibliographie*/
    std::vector<Reference*> m_vReferences; /*\brief (vecteur) contient la liste des pointeurs des References dans la bibliographie*/
    std::vector<Reference*>::iterator iter; /**<\brief (iterateur) iterateur sur le vecteur m_vReferences.*/
  };
}

#endif /* BIBLIOGRAPHIE_H */

