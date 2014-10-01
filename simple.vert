    varying vec4 secondaryColor;

    void main( void )
    {
        // Normal MVP transform
        vec4 clipCoord = gl_ModelViewProjectionMatrix * gl_Vertex;
        gl_Position = clipCoord;

        // Copy primary color
        gl_FrontColor = gl_Color;

        // Calculate NDC
        vec3 ndc = clipCoord.xyz / clipCoord.w;

        // Map from [-1,1] to [0,1] before outputting
        secondaryColor = vec4( ( ndc * 0.5 ) + 0.5, 1.0 );
    }

