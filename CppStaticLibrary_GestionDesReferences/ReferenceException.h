/**
 * \file  ReferenceException.h
 * \author M4ST3R-Y0DA-44
 * \brief Ce fichier contient les declaration pour la Classe ReferenceException, ReferenceDejaPresenteException et ReferenceAbsenteException..
 *
 * \date Created on 7 décembre 2021, 04:04
 */

#ifndef REFERENCEEXCEPTION_H
#define REFERENCEEXCEPTION_H

#include <string>
#include <stdexcept>

/**
 * \class ReferenceException
 * \brief class qui s'occupe de gerer les exception liee aux references.
 */
class ReferenceException : public std::runtime_error
{
public:
  /**
   * \fn ReferenceException (const std::string& p_raison)
   * \brief Constructeur de la classe ReferenceException
   * \param p_raison (string) raison de l'exception
   */
  ReferenceException (const std::string& p_raison);

  /** \fn virtual ~ReferenceException() {}
   * \brief destructeur de la classe ReferenceException qui declenche aussi les destructeurs des classes derives*/
  virtual
  ~ReferenceException () { };
};

/**
 * \class ReferenceDejaPresenteException
 * \brief classe qui s'occupe de gerer l'exception d'ajout d'un doublons de references pour la bibliographie */
class ReferenceDejaPresenteException : public ReferenceException
{
public:
  /**
   * \fn ReferenceDejaPresenteException (const std::string& p_raison)
   * \brief constructeur de la classe ReferenceDejaPresenteException
   * \param p_raison (string) raison de l'exception*/
  ReferenceDejaPresenteException (const std::string& p_raison);
};

/**
 * \class ReferenceAbsenteException
 * \brief class qui s'occupe de la gestion de l'exception de la tentative d'effacement d'une reference absente dans la bibliographie.*/
class ReferenceAbsenteException : public ReferenceException
{
public:
  /**
   * \fn ReferenceAbsenteException(const std::string& p_raison)
   * \brief constructeur de la classe ReferenceAbsenteException
   * \param p_raison (string) raison de l'exception*/
  ReferenceAbsenteException (const std::string& p_raison);
};

#endif /* REFERENCEEXCEPTION_H */

