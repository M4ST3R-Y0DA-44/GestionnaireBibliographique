/**
 * \file  ContratException.h
 * \brief Ce fichier contient toute les declarations comprise dans la classe ContratException
 * \author M4ST3R-Y0DA-44
 *
 * \date Created on 18 novembre 2021, 15:05
 */

#ifndef CONTRATEXCEPTION_H
#define CONTRATEXCEPTION_H

#include <string>
#include <stdexcept>

/**
 * \class ContratException
 * \brief Classe qui verifie les conditions de validation et qui lance des erreurs lorsque les donnee sont non valide
 *
 * Attributs: std::string m_expression expression du message d'erreur,
 * std::string m_fichier le nom du fichier dans lequel se trouve le message d'erreur
 * unsigned int m_ligne le numero de la ligne de l'erreur
 *
 */


class ContratException : public std::logic_error
{
  /** \fn ContratException (std::string, int, std::string, std::string)
   * \brief constructeur de la classe ContratException
   * \param std::string
   * \param int
   * \param std::string
   *\param std::string
   *
   ** \fn ~ContratException
   * \brief destructeur de la classe ContratException
   *
   ** \fn std::string reqTexteException ()
   * \brief fonction qui retourne le message d'erreur
   */
public:
  ContratException (std::string, unsigned int, std::string, std::string);

  ~ContratException () throw () { };
  const std::string reqTexteException ()const;

private:
  std::string m_expression;
  std::string m_fichier;
  unsigned int m_ligne;


};

/**
 * \class AssertionException
 * \brief Classe pour la gestion des erreurs d'assertion.
 */

class AssertionException : public ContratException
{
public:
  AssertionException (std::string, unsigned int, std::string);
};

/**
 * \class PreconditionException
 * \brief Classe pour la gestion des erreurs de précondition.
 */

class PreconditionException : public ContratException
{
public:
  PreconditionException (std::string, unsigned int, std::string);
};

/**
 * \class PostconditionException
 * \brief Classe pour la gestion des erreurs de postcondition.
 */
class PostconditionException : public ContratException
{
public:
  PostconditionException (std::string, unsigned int, std::string);
};

/**
 * \class InvariantException
 * \brief Classe pour la gestion des erreurs d'invariant.
 */
class InvariantException : public ContratException
{
public:
  InvariantException (std::string, unsigned int, std::string);
};

// --- Définition des macros de contrôle de la théorie du contrat

#if !defined(NDEBUG)
// --- Mode debug

#define INVARIANTS() \
      verifieInvariant()

#define ASSERTION(f)     \
      if (!(f)) throw AssertionException(__FILE__,__LINE__, #f);
#define PRECONDITION(f)  \
      if (!(f)) throw PreconditionException(__FILE__, __LINE__, #f);
#define POSTCONDITION(f) \
      if (!(f)) throw PostconditionException(__FILE__, __LINE__, #f);
#define INVARIANT(f)   \
      if (!(f)) throw InvariantException(__FILE__,__LINE__, #f);

// --- LE MODE RELEASE
#else

#define PRECONDITION(f);
#define POSTCONDITION(f);
#define INVARIANTS();
#define INVARIANT(f);
#define ASSERTION(f);


#endif  // --- if !defined (NDEBUG)
#endif /* CONTRATEXCEPTION_H */

