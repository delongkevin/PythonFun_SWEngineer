/*
 * File:   BasicTracker.h
 * Author: Joao F. Henriques, Joao Faro, Christian Bailer
 * Contact address: henriques@isr.uc.pt, joaopfaro@gmail.com, Christian.Bailer@dfki.de
 * Instute of Systems and Robotics- University of COimbra / Department Augmented Vision DFKI
 *
 * This source code is provided for for research purposes only. For a commercial license or a different use case please contact us.
 * You are not allowed to publish the unmodified sourcecode on your own e.g. on your webpage. Please refer to the official download page instead.
 * If you want to publish a modified/extended version e.g. because you wrote a publication with a modified version of the sourcecode you need our
 * permission (Please contact us for the permission).
 *
 * We reserve the right to change the license of this sourcecode anytime to BSD, GPL or LGPL.
 * By using the sourcecode you agree to possible restrictions and requirements of these three license models so that the license can be changed
 * anytime without you knowledge.
 */


#ifndef TRACKERC_H
#define TRACKERC_H
#ifdef _WIN32
    #include <MECL/mecl.h>
#else
    #include "mecl/mecl.h"
#endif // _WIN32

class ITrackerC
{
public:
    ITrackerC()  {}
    virtual  ~ITrackerC() { }

    virtual void init_c( const Recti& roi, mecl::core::Matrix<uint8_t, 400, 640, e_Default> i_img ) = 0;
    virtual Recti update_c( mecl::core::Matrix<uint8_t, 400, 640, e_Default> image ) = 0;


protected:
    Rectf _roi_c;
};



#endif // !TRACKERC_H
