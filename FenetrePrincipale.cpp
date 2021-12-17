/**
 * \file   FenetrePrincipale.cpp
 * \author M4ST3R-Y0DA-44
 * \brief Ce fichier contient les definition pour le classe FenetrePrincipale.
 *
 * \date Created on 7 décembre 2021, 00:03
 */

#include "FenetrePrincipale.h"
#include "AjoutJournalInterface.h"
#include "AjoutOuvrageInterface.h"
#include "SupressionReferenceInterface.h"
#include "ReferenceException.h"
#include "Ouvrage.h"
#include "Journal.h"
#include <QMessageBox>

using namespace biblio;
using namespace std;


/*Constructeur de la FenetrePrioncipale*/
FenetrePrincipale::FenetrePrincipale ()
{
  widget.setupUi (this);
}


/*Destructeur de la FenetrePrincipale*/
FenetrePrincipale::~FenetrePrincipale () { }


/*Methode d'ajout d'une Reference dans l'attribut m_BibliographieTp4*/
void
FenetrePrincipale::ajouterReference (const Reference& p_nouvelleReference)
{
  try
    {
      m_BibliographieTp4.ajouterReference (p_nouvelleReference);
    }
  catch (ReferenceDejaPresenteException& e)
    {
      QString message ("La reference est deja presente dans cette Bibliographie. ");
      QMessageBox::information (this, "ERREUR", message);
    }
}


/*Methode de suppression d'un attribut selon l'identifiant en parametre*/
void
FenetrePrincipale::supprimerReference (const string& p_identifiant)
{
  try
    {
      QString message ("Etes-vous certain de vouloir supprimer la Reference. Vous ne pourrez pas revenir en arriere.");
      QMessageBox::StandardButton reply;
      reply = QMessageBox::question (this, "Supression de la reference", message, QMessageBox::Yes | QMessageBox::No);
      if (reply == QMessageBox::Yes)
        {
          m_BibliographieTp4.supprimerReference (p_identifiant);
        }
    }
  catch (ReferenceAbsenteException & e)
    {
      QString message ("L'identifiant demander ne fait pas partie de la Bibliographie. Veuillez verifier votre code identifiant. ");
      QMessageBox::information (this, "ERREUR", message);
    }
}


/*Methode de lecture de la liste des reference sous un format formate*/
const string
FenetrePrincipale::reqListeReferenceFormate ()
{
  return m_BibliographieTp4.reqBibliographieFormate ();
}


/*Methode Slot pour ajouter une reference de type Journal*/
void
FenetrePrincipale::DialogJournal ()
{
  AjoutJournalInterface journal;
  if (journal.exec ())
    {
      ajouterReference (Journal (journal.reqNomJournal ().toStdString (), journal.reqVolume (), journal.reqNumero (), journal.reqPage (), journal.reqNomAuteur ().toStdString (), journal.reqTitre ().toStdString (), journal.reqAnnee (), journal.reqCodeIsnn ().toStdString ()));

      widget.txtAfficherBibliographie->setText (QString::fromStdString (reqListeReferenceFormate ()));
    }
}


/*Methode Slot pour ajouter une reference de type Ouvrage*/
void
FenetrePrincipale::DialogOuvrage ()
{
  AjoutOuvrageInterface ouvrage;
  if (ouvrage.exec ())
    {
      ajouterReference (Ouvrage (ouvrage.reqNomEditeur ().toStdString (), ouvrage.reqVille ().toStdString (), ouvrage.reqNomAuteur ().toStdString (), ouvrage.reqTitre ().toStdString (), ouvrage.reqAnnee (), ouvrage.reqCodeIsbn ().toStdString ()));
      widget.txtAfficherBibliographie->setText (QString::fromStdString (reqListeReferenceFormate ()));
    }
}


/*Methode Slot de retrait d'une Reference dans le Bibliographie.*/
void
FenetrePrincipale::DialogDeleteReference ()
{
  SupressionReferenceInterface reference;
  if (reference.exec ())
    {
      supprimerReference (reference.reqCodeId ().toStdString ());
      widget.txtAfficherBibliographie->setText (QString::fromStdString (reqListeReferenceFormate ()));
    }
}
