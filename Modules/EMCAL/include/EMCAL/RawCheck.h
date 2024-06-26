// Copyright 2019-2020 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

///
/// \file   RawCheck.h
/// \author Cristina Terrevoli
///

#ifndef QC_MODULE_EMCAL_EMCALRAWCHECK_H
#define QC_MODULE_EMCAL_EMCALRAWCHECK_H

#include "QualityControl/CheckInterface.h"

class TH1F;

using namespace o2::quality_control::core;

namespace o2::quality_control_modules::emcal
{

/// \brief EMCAL raw data check
/// It is final because there is no reason to derive from it. Just remove it if needed.
/// \author Cristina Terrevoli
class RawCheck final : public o2::quality_control::checker::CheckInterface
{
 public:
  /// Default constructor
  RawCheck() = default;
  /// Destructor
  ~RawCheck() override = default;

  // Override interface
  void configure() override;
  Quality check(std::map<std::string, std::shared_ptr<MonitorObject>>* moMap) override;
  void beautify(std::shared_ptr<MonitorObject> mo, Quality checkResult = Quality::Null) override;
  std::string getAcceptedType() override;

  /************************************************
   * Switches for InfoLogger Messages             *
   ************************************************/
  bool mIlMessageBunchMinAmpCheckSM = false;       ///< Switch for IL message for Bunch Min. amplitude check at supermodule level
  bool mIlMessageBunchMinAmpCheckDetector = false; ///< Switch for IL message for Bunch Min. amplitude check at subdetector level
  bool mIlMessageBunchMinAmpCheckFull = false;     ///< Switch for IL message for Bunch Min. amplitude check at full detector level
  bool mILMessageRawErrorCheck = false;            ///< Switch for IL message for error code
  bool mILMessageNoisyFECCheck = false;            ///< Switch for IL message for noisy FEC
  bool mILMessagePayloadSizeCheck = false;         ///< Switch for IL message for large payload size

  /************************************************
   * sigma cuts                                   *
   ************************************************/
  double mNsigmaFECMaxPayload = 2.; ///< Number of sigmas used in the FEC max payload check
  double mNsigmaPayloadSize = 2.;   ///< Number of sigmas used in the payload size check

  /************************************************
   * Settings for bunch min. amp checker          *
   ************************************************/

  int mBunchMinCheckMinEntries = 0;          ///< Min. number of entries for bunch min. amplitude in evaluation region
  double mBunchMinCheckFractionSignal = 0.5; ///< Fraction of entries in signal region for bunch min. amp checker

  ClassDefOverride(RawCheck, 2);
};

} // namespace o2::quality_control_modules::emcal

#endif // QC_MODULE_EMCAL_EMCALRAWCHECK_H
