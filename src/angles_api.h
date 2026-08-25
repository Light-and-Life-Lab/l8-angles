#ifndef ANGLES_API
#define ANGLES_API

/* IAS Library Includes */
#include "ias_logging.h"
#include "ias_angle_gen_distro.h"

/* Local Includes */
#include "l8_angles.h"

int calculate_angles
(
    const IAS_ANGLE_GEN_METADATA *metadata, 
    int line,                               
    int samp,                               
    int band_index,                         
    ANGLE_TYPE angle_type,                  
    double *sat_angles,                     
    double *sun_angles                      
);

const double *get_active_lines
(
    const IAS_ANGLE_GEN_METADATA *metadata, 
    int band_index                          
);

const double *get_active_samples
(
    const IAS_ANGLE_GEN_METADATA *metadata, 
    int band_index                          
);

int get_frame
(
    const IAS_ANGLE_GEN_METADATA *metadata,
    int band_index,                         
    ANGLES_FRAME *frame                     
);

#endif // ANGLES_API