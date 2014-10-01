    varying vec4 secondaryColor;
    uniform vec4 color;

    void main(void)
    {
        // Mix primary and secondary colors 50:50
//        gl_FragColor = mix( gl_Color, vec4( vec3( secondaryColor ), 1.0 ), 0.5 );
        gl_FragColor = color;
    }

