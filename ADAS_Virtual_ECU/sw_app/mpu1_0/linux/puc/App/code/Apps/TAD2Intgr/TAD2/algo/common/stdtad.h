// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [03-Apr-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __STDTAD__H_
#define __STDTAD__H_


#include "db.h"
#include "diag.h"
#ifdef DIAGNOSTICS
    #include "global.h"
    #include "fo.h"
#endif


#include "Defines.h"
#include "MemoryPool.h"
#include "ImageProcessing.h"


namespace mms
{
    template <class max_type>
    max_type maximum( max_type a, max_type b )
    {
        max_type ret_val_max;

        if( a > b )
        {
            ret_val_max = a;
        }
        else
        {
            ret_val_max = b;
        }

        return ret_val_max;
    }

    template <class min_type>
    min_type minimum( min_type a, min_type b )
    {
        min_type ret_val_min;

        if( a < b )
        {
            ret_val_min = a;
        }
        else
        {
            ret_val_min = b;
        }

        return ret_val_min;
    }

    template <class squeeze_type>
    squeeze_type squeeze( squeeze_type v, squeeze_type a, squeeze_type b )
    {
        squeeze_type result_min;
        squeeze_type result_final;
        result_min = minimum<squeeze_type>( b, v );
        result_final = maximum<squeeze_type>( a, result_min );
        return result_final;
    }

    template <class abs_type>
    abs_type absolute( abs_type a )
    {
        abs_type ret_val;

        if( a < 0 )
        {
            ret_val = -a;
        }
        else
        {
            ret_val = a;
        }

        return ret_val;
    }
}

#endif // !__STDTAD__H_
