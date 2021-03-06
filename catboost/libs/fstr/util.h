#pragma once

#include <catboost/libs/data/pool.h>
#include <catboost/libs/model/model.h>

#include <util/generic/vector.h>

TVector<TVector<double>> CollectLeavesStatistics(const TPool& pool, const TFullModel& model);
