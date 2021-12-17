/**
 * \file  AjoutJournalInterface.h
 * \author M4ST3R-Y0DA-44
 * \brief ce fichier contient la declaration de la classe AjoutJournalInterface.
 *
 * \date Created on 7 décembre 2021, 16:20
 */

#ifndef _AJOUTJOURNALINTERFACE_H
#define _AJOUTJOURNALINTERFACE_H

#include "ui_AjoutJournalInterface.h"

/**
 * \class AjoutJournalInterface
 * \brief class qui permet la creation de la fenetre d'ajout une reference de type Journal. */
class AjoutJournalInterface : public QDialog
{
  Q_OBJECT
public:
  /**
   * \fn AjoutJournalInterface ()
   * \brief Constructeur de la classe AjoutJournalInterface*/
  AjoutJournalInterface ();

  /**
   * \fn virtual ~AjoutJournalInterface ()
   * \brief Destructeur de la classe AjoutJournalInterface*/
  virtual ~AjoutJournalInterface ();

  /**
   * \fn QString reqNomAuteur () const
   * \brief methode de lecture du text dans le champs nom auteur de l'interface
   * \return (QString) contient le nom de l'auteur sous une chaine string. */
  QString reqNomAuteur () const;

  /**
   * \fn QString reqTitre () const
   * \brief methode de lecture du text dans le champ titre de l'interface
   * \return (QString) contient le titre sous une chaine string. */
  QString reqTitre () const;

  /**
   * \fn int reqAnnee () const
   * \brief methode de lecture de la valeur dans le champ annee de l'interface.
   * \return (int) annee de publication du champs de l'interface*/
  int reqAnnee () const;

  /**
   * \fn QString reqNomJournal () const
   * \brief methode de lecture du nom du journal dans le champs nom du journal de l'interface.
   * \return (QString) nom du journal contenue par le champs de l'interface.*/
  QString reqNomJournal () const;

  /**
   * \fn reqVolume () const
   * \brief methode qui fait la lecture du numero de volume dans le champs volume de l'interface.
   * \return (int) numero de volume contenue dans le champs de l'interface. */
  int reqVolume () const;

  /** \fn reqNumero () const
   * \brief methode qui fait la lecture du numero dans le champs numero de l'interface.
   * \return (int) numero contenue dans le champs de l'interface. */
  int reqNumero () const;

  /** \fn reqPage () const
   * \brief methode qui fait la lecture du numero de la page dans le champs page de l'interface.
   * \return (int) page contenue dans le champs de l'interface. */
  int reqPage () const;

  /**
   * \fn QString reqCodeIssn () const
   * \brief methode de lecture du code ISSN contenue dans le champs code isnn de l'application.
   * \return (QString) code ISNN contenue dans le champs code de l'application. */
  QString reqCodeIsnn () const;

private slots:
  /**
   * \fn void validerJournal()
   * \brief methode (slot) qui permet de verifier les entree du Journal*/
  void validerJournal ();

private:
  Ui::AjoutJournalInterface widget; /**<\brief ui de AjoutJournalInterface*/
};

#endif /* _AJOUTJOURNALINTERFACE_H */
