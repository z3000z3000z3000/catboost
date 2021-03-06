#include "classification_utils.h"
#include "metric_holder.h"

#include <util/generic/array_ref.h>
#include <util/generic/ymath.h>

TMetricHolder CalcBalancedAccuracyMetric(TConstArrayRef<TVector<double>> approx,
                                         TConstArrayRef<float> target,
                                         TConstArrayRef<float> weight,
                                         int begin,
                                         int end,
                                         int positiveClass,
                                         double border) {
    // Stats[0] == truePositive, Stats[1] == targetPositive, Stats[2] == trueNegative, Stats[3] == targetNegative
    TMetricHolder metric(4);

    double approxPositive;
    GetPositiveStats(
            approx,
            target,
            weight,
            begin,
            end,
            positiveClass,
            border,
            &metric.Stats[0],
            &metric.Stats[1],
            &approxPositive
    );

    GetSpecificity(approx, target, weight, begin, end, positiveClass, border, &metric.Stats[2], &metric.Stats[3]);

    return metric;
}

double CalcBalancedAccuracyMetric(const TMetricHolder& error) {
    double sensitivity = error.Stats[1] > 0 ? error.Stats[0] / error.Stats[1] : 0;
    double specificity = error.Stats[3] > 0 ? error.Stats[2] / error.Stats[3] : 0;
    return error.Stats[0] == error.Stats[1] && error.Stats[2] == error.Stats[3] ? 1 : (sensitivity + specificity) / 2;
}
