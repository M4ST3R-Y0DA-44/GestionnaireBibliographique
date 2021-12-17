/*
 * \file   AjoutOuvrageInterface.cpp
 * \author M4ST3R-Y0DA-44
 * \brief ce fichier contient les definition de la classe AjoutOuvrageInterface.
 *
 * \date Created on 7 décembre 2021, 16:33
 */

#include "AjoutOuvrageInterface.h"
#include "validationFormat.h"
#include <QMessageBox>


/*Constructeur*/
AjoutOuvrageInterface::AjoutOuvrageInterface ()
{
  widget.setupUi (this);
}


/*Destructeur*/
AjoutOuvrageInterface::~AjoutOuvrageInterface () { }


/*Methode de lecture de nom de l'auteur dans l'interface*/
QString
AjoutOuvrageInterface::reqNomAuteur () const
{
  return widget.txtNomAutheur->text ();
}


/*Methode de lecture du titre dans l'interface*/
QString
AjoutOuvrageInterface::reqTitre () const
{
  return widget.txtTitre->text ();
}


/*Methode de lecture de l'annee dans l'interface*/
int
AjoutOuvrageInterface::reqAnnee () const
{
  return widget.spinboxAnnee->value ();
}


/*methode de lecture de nom de l'editeur dans l'interface*/
QString
AjoutOuvrageInterface::reqNomEditeur () const
{
  return widget.txtNomEditeur->text ();
}


/*methode de lecture de la ville dans l'interface*/
QString
AjoutOuvrageInterface::reqVille () const
{
  return widget.txtVille->text ();
}


/*methode de lecture du code isbn dans l'interface*/
QString
AjoutOuvrageInterface::reqCodeIsbn () const
{
  return widget.txtISBN->text ();
}


/*methode de validation des donnees*/
void
AjoutOuvrageInterface::validerOuvrage ()
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
  if (! util::validerFormatNom (reqNomEditeur ().toStdString ()))
    {
      QString message ("le nom de l'editeur ne peut pas etre vide et ne peut pas etre composer de caractere speciaux ou numerique. ");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (! util::validerFormatNom (reqVille ().toStdString ()))
    {
      QString message ("le nom de la ville ne peut pas etre vide et ne peut pas etre composer de caractere speciaux ou numerique. ");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (! util::validerCodeIsbn (reqCodeIsbn ().toStdString ()))
    {
      QString message ("le code Isbn doit etre de format valide.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  accept ();
}