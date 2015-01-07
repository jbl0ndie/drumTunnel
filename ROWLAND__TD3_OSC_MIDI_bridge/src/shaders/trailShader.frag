#extension GL_ARB_texture_rectangle : enable

/* ---------------------------------------------------------------------
 -------------------------------VARIABLES-------------------------------
 ----------------------------------------------------------------------*/


// Sampler

uniform sampler2DRect tex;
uniform sampler2DRect lastTex; // For motion blur


//// Input and output


// Motion blur

uniform float attack;
uniform float decay;

uniform float thrsh;

/* ---------------------------------------------------------------------
-------------------------------FUNCTIONS--------------------------------
----------------------------------------------------------------------*/


vec4 motionBlurFilter(vec4 crntCol)
{

    vec4 lastTexel0 = texture2DRect(lastTex, gl_TexCoord[0].xy);
    
    if (crntCol.r+crntCol.g+crntCol.b >= lastTexel0.r+lastTexel0.g+lastTexel0.b)
    {
    
    return ((crntCol-lastTexel0)*attack)+lastTexel0;
    }
    else
    {
        
        vec4 col = ((crntCol-lastTexel0)*decay)+lastTexel0;
        if (col.r+col.g+col.b/3.0 < thrsh) {
        //return ((crntCol-lastTexel0)*decay)+lastTexel0;
            return vec4(0.0,0.0,0.0,1.0);
            //return ((crntCol-lastTexel0)*decay)+lastTexel0*0.0001;
        }
        else{
            
        
            return ((crntCol-lastTexel0)*decay)+lastTexel0;
        }
    }
}

 /*---------------------------------------------------------------------
 ---------------------------------MAIN----------------------------------
 ----------------------------------------------------------------------*/

void main(void) {
    
    vec4 texel0 =  texture2DRect(tex, gl_TexCoord[0].xy);
    
    vec4 col = motionBlurFilter(texel0);
    
//    if (((col.r+col.g+col.b)/3.0) < thrsh) {
//        col.r = 0.0;
//        col.g = 0.0;
//        col.b = 0.0;
//        //col.a = 0.0;
//        
//    }


    gl_FragColor = col ;

}

    
    
