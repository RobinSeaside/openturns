//                                               -*- C++ -*-
/**
 * @brief The class that implements the gradient of an analytical function.
 *
 * Copyright 2005-2017 Airbus-EDF-IMACS-Phimeca
 *
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 *
 *
 */

#ifndef OPENTURNS_SYMBOLICGRADIENT_HXX
#define OPENTURNS_SYMBOLICGRADIENT_HXX

#include "openturns/NumericalMathGradientImplementation.hxx"
#include "openturns/SymbolicEvaluation.hxx"

BEGIN_NAMESPACE_OPENTURNS

/**
 * @class SymbolicGradient
 *
 * The class that implement the gradient of an analytical function.
 */
class OT_API SymbolicGradient
  : public NumericalMathGradientImplementation
{
  CLASSNAME;
public:

  /** Default constructor */
  SymbolicGradient();

  /** Default constructor */
  SymbolicGradient(const SymbolicEvaluation & evaluation);

  /** Virtual constructor */
  virtual SymbolicGradient * clone() const;

  /** Comparison operator */
  Bool operator ==(const SymbolicGradient & other) const;

  /** String converter */
  virtual String __repr__() const;
  virtual String __str__(const String & offset = "") const;

  /** Operator () */
  using NumericalMathGradientImplementation::gradient;
  Matrix gradient(const NumericalPoint & inP) const;

  /** Accessor for input point dimension */
  UnsignedInteger getInputDimension() const;

  /** Accessor for output point dimension */
  UnsignedInteger getOutputDimension() const;

  /** Accessor to a specific formula */
  String getFormula(const UnsignedInteger i,
                    const UnsignedInteger j) const;

  /** Get the i-th marginal function */
  Implementation getMarginal(const UnsignedInteger i) const;

  /** Get the function corresponding to indices components */
  Implementation getMarginal(const Indices & indices) const;

  /** Method save() stores the object through the StorageManager */
  void save(Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  void load(Advocate & adv);

protected:

private:

  /* Must initialize the parser at the first call to operator() as the
     reference associated with the variables may have change after the construction */
  void initialize() const;

  mutable Bool isInitialized_;
  mutable Bool isAnalytical_;
  SymbolicEvaluation evaluation_;

  /** A mathematical expression parser from the muParser library */
  mutable AnalyticalParser parser_;

}; /* class SymbolicGradient */


END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_SYMBOLICGRADIENT_HXX */
