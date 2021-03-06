//                                               -*- C++ -*-
/**
 *  @brief Class for a linear numerical math gradient impelmentation
 *
 *  Copyright 2005-2017 Airbus-EDF-IMACS-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef OPENTURNS_CONSTANTNUMERICALMATHGRADIENTIMPLEMENTATION_HXX
#define OPENTURNS_CONSTANTNUMERICALMATHGRADIENTIMPLEMENTATION_HXX

#include "openturns/NumericalMathGradientImplementation.hxx"
#include "openturns/Matrix.hxx"

BEGIN_NAMESPACE_OPENTURNS




/**
 * @class ConstantNumericalMathGradientImplementation
 *
 * This class offers an interface for an real numerical mathematical gradient
 * implementations into the platform. It realizes the computation of the image matrix
 * of a vector (aka NumericalPoint) through the gradient. The
 * gradient may be loaded in an external way through a wrapper.
 */
class OT_API ConstantNumericalMathGradientImplementation
  : public NumericalMathGradientImplementation
{
  CLASSNAME;
public:


  /** Default constructor */
  ConstantNumericalMathGradientImplementation();

  /** Parameter constructor */
  ConstantNumericalMathGradientImplementation(const Matrix & constant);

  /** Virtual constructor */
  virtual ConstantNumericalMathGradientImplementation * clone() const;

  /** Comparison operator */
  Bool operator ==(const ConstantNumericalMathGradientImplementation & other) const;

  /** String converter */
  virtual String __repr__() const;
  virtual String __str__(const String & offset = "") const;

  /* Here is the interface that all derived class must implement */

  /** Gradient method */
  virtual Matrix gradient(const NumericalPoint & inP) const;

  /** Accessor for input point dimension */
  virtual UnsignedInteger getInputDimension() const;

  /** Accessor for output point dimension */
  virtual UnsignedInteger getOutputDimension() const;

  /** Accessor for the constant term */
  Matrix getConstant() const;

  /** Method save() stores the object through the StorageManager */
  void save(Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  void load(Advocate & adv);

protected:


private:
  Matrix constant_;
}; /* class ConstantNumericalMathGradientImplementation */


END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_CONSTANTNUMERICALMATHGRADIENTIMPLEMENTATION_HXX */
