/**
 * \file  FenetrePrincipale.h
 * \author M4ST3R-Y0DA-44
 * \brief Ce fichier contient les declaration de la classe FenetrePrincipale.
 * \date Created on 7 décembre 2021, 00:03
 */

#ifndef _FENETREPRINCIPALE_H
#define _FENETREPRINCIPALE_H

#include "ui_FenetrePrincipale.h"
#include "Bibliographie.h"

/**
 * \class FenetrePrincipale
 * \brief classe qui permet la creation d'une fenetre principale pour notre application a Bibliographie.
 */
class FenetrePrincipale : public QMainWindow
{
  Q_OBJECT
public:
  /**
   * \fn FenetrePrincipale ()
   * \brief Constructeur de la classe FenetrePrincipale*/
  FenetrePrincipale ();

  /**
   * \fn virtual ~FenetrePrincipale ()
   * \brief fonction de destructeur de la classe FenetrePrincipale*/
  virtual ~FenetrePrincipale ();

  /**
   * \fn void ajouterReference (const biblio::Reference& p_nouvelleReference)
   * \brief methode qui permet de faire l'ajout d'une reference dans la Bibliographie
   * \param p_nouvelleReference (Reference&) nouvelle reference a ajouter*/
  void ajouterReference (const biblio::Reference& p_nouvelleReference);

  /**
   * \fn void supprimerReference (const std::string& p_identifiant)
   * \brief methode qui permet de faire la supression d'une reference dont l'identifiant est passer en paramatre
   * @param p_identifiant (string) identifiant ISSN ou ISBN a supprimer de la Bibliographie.*/
  void supprimerReference (const std::string& p_identifiant);

  /**
   * \fn const std::string reqListeReferenceFormate()
   * \brief methode qui permet de faire la lecture de la bibliographie et d'afficher la liste des reference dans un format formate a l'ecran
   * \return (string) la liste des reference formate */
  const std::string reqListeReferenceFormate ();


private slots:
  /**
   * \fn void DialogJournal()
   * \brief methode (slot) pour la page Dialogjournal qui permet d'ajouter un Journal a la bibliographie*/
  void DialogJournal ();

  /**
   * \fn void DialogOuvrage()
   * \brief methode (slot) pour la page DialogOuvrage qui permet d'ajouter un Ouvrage a la bibliographie*/
  void DialogOuvrage ();

  /**
   * \fn void DialogDeleteReference ()
   * \brief  methode (slot) pour la page DialogDeleteReference qui permet de supprimer une Reference de la Bibliographie */
  void DialogDeleteReference ();

private:
  biblio::Bibliographie m_BibliographieTp4 = biblio::Bibliographie ("tp4"); /**<\brief objet Bibliographie associe a la FenetrePrincipale*/
  Ui::FenetrePrincipale widget; /**<\brief ui de la FenetrePrincipale*/
};

#endif /* _FENETREPRINCIPALE_H */
