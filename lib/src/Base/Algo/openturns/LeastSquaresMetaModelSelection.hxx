//                                               -*- C++ -*-
/**
 *  @brief Basis selection algorithm
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
#ifndef OPENTURNS_LEASTSQUARESMETAMODELSELECTION_HXX
#define OPENTURNS_LEASTSQUARESMETAMODELSELECTION_HXX

#include "openturns/ApproximationAlgorithmImplementation.hxx"
#include "openturns/FittingAlgorithm.hxx"
#include "openturns/BasisSequenceFactory.hxx"
#include "openturns/CorrectedLeaveOneOut.hxx"
#include "openturns/LARS.hxx"

BEGIN_NAMESPACE_OPENTURNS

/**
 * @class LeastSquaresMetaModelSelection
 *
 * Basis selection algorithm
 */
class OT_API LeastSquaresMetaModelSelection
  : public ApproximationAlgorithmImplementation
{
  CLASSNAME;

public:

  /** Default constructor */
  LeastSquaresMetaModelSelection(const NumericalSample & x,
                                 const NumericalSample & y,
                                 const Basis & psi,
                                 const Indices & indices,
                                 const BasisSequenceFactory & basisSequenceFactory = LARS(),
                                 const FittingAlgorithm & fittingAlgorithm = CorrectedLeaveOneOut());

  /** Default constructor */
  LeastSquaresMetaModelSelection(const NumericalSample & x,
                                 const NumericalSample & y,
                                 const NumericalPoint & weight,
                                 const Basis & psi,
                                 const Indices & indices,
                                 const BasisSequenceFactory & basisSequenceFactory = LARS(),
                                 const FittingAlgorithm & fittingAlgorithm = CorrectedLeaveOneOut());

  /** Virtual constructor */
  virtual LeastSquaresMetaModelSelection * clone() const;

  /** String converter */
  virtual String __repr__() const;

  /** BasisSequenceFactory accessor */
  void setBasisSequenceFactory(const BasisSequenceFactory & basisSequenceFactory);
  BasisSequenceFactory getBasisSequenceFactory() const;

  /** FittingAlgorithm accessor */
  void setFittingAlgorithm(const FittingAlgorithm & fittingAlgorithm);
  FittingAlgorithm getFittingAlgorithm() const;

  /** Perform the selection */
  virtual void run();
#ifndef SWIG
  virtual void run(const DesignProxy & proxy);
#endif

  /** Method save() stores the object through the StorageManager */
  virtual void save(Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  virtual void load(Advocate & adv);

protected:
  friend class Factory<LeastSquaresMetaModelSelection>;

  /** Default constructor */
  LeastSquaresMetaModelSelection();

  /** Algorithm that builds the BasisSequence */
  BasisSequenceFactory basisSequenceFactory_;

  /** Basis selection algorithm */
  FittingAlgorithm fittingAlgorithm_;


}; /* class LeastSquaresMetaModelSelection */

END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_LEASTSQUARESMETAMODELSELECTION_HXX */
