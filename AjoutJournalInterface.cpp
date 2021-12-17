/**
 * \file  AjoutJournalInterface.cpp
 * \author M4ST3R-Y0DA-44
 * \brief ce fichier contient les definitions de la classe AjoutJournalInterface.
 *
 * \date Created on 7 décembre 2021, 16:20
 */
#include "AjoutJournalInterface.h"
#include <QMessageBox>
#include "validationFormat.h"


/*Constructeur*/
AjoutJournalInterface::AjoutJournalInterface ()
{
  widget.setupUi (this);
}


/*Destructeur*/
AjoutJournalInterface::~AjoutJournalInterface () { }


/*methode lecture du nom auteur interface*/
QString
AjoutJournalInterface::reqNomAuteur () const
{
  return widget.txtNomAuteur->text ();
}


/*Methode lecture du titre dans l'interface*/
QString
AjoutJournalInterface::reqTitre () const
{
  return widget.txtTitre->text ();
}


/*Methode de lecture de l'annee dans l'interface*/
int
AjoutJournalInterface::reqAnnee () const
{
  return widget.spinBoxAnnee->value ();
}


/*Methode de lecture du nom de journal dans l'interface*/
QString
AjoutJournalInterface::reqNomJournal () const
{
  return widget.txtNomJournal->text ();
}


/*Methode de lecture du volume dans l'interface*/
int
AjoutJournalInterface::reqVolume () const
{
  return widget.spinBoxVolume->value ();
}


/*methode de lecture du numero dans l'interface*/
int
AjoutJournalInterface::reqNumero () const
{
  return widget.spinBoxNumero->value ();
}


/*Methode de lecture de la page dans l'interface*/
int
AjoutJournalInterface::reqPage () const
{
  return widget.spinBoxPage->value ();
}


/*Methode de lecture du code Issn*/
QString
AjoutJournalInterface::reqCodeIsnn () const
{
  return widget.txtISSN->text ();
}


/*Methode de validation des entree*/
void
AjoutJournalInterface::validerJournal ()
{

  if (! util::validerFormatNom (reqNomAuteur ().toStdString ()))
    {
      QString message ("le nom de l'auteur ne peut pas etre vide et ne peut pas etre composer de caractere speciaux ou numerique. ");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqTitre ().isEmpty ())
    {
      QString message ("le titre ne peut pas etre vide.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqAnnee () <=  0)
    {
      QString message ("l'annee doit etre superieur a 0.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (! util::validerFormatNom (reqNomJournal ().toStdString ()))
    {
      QString message ("le nom du Journal ne peut pas etre vide et ne peut pas etre composer de caractere speciaux ou numerique. ");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqVolume () <=  0)
    {
      QString message ("le volume doit etre superieur a 0.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqNumero () <=  0)
    {
      QString message ("le numero doit etre superieur a 0.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqPage () <=  0)
    {
      QString message ("la page doit etre superieur a 0.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (! util::validerCodeIssn (reqCodeIsnn ().toStdString ()))
    {
      QString message ("le code Isnn doit etre de format valide.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  accept ();
}
