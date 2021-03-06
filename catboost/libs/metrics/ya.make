LIBRARY()



SRCS(
    auc.cpp
    balanced_accuracy.cpp
    brier_score.cpp
    classification_utils.cpp
    dcg.cpp
    hinge_loss.cpp
    kappa.cpp
    llp.cpp
    metric.cpp
    pfound.cpp
    precision_recall_at_k.cpp
    sample.cpp
)

PEERDIR(
    catboost/libs/data_types
    catboost/libs/eval_result
    catboost/libs/helpers
    catboost/libs/options
    library/containers/2d_array
    library/threading/local_executor
)

GENERATE_ENUM_SERIALIZATION(metric.h)

END()
