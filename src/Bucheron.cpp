   #   i   n   c   l   u   d   e       "   B   u   c   h   e   r   o   n   .   h   "      
      
   #   i   n   c   l   u   d   e       <   s   t   r   i   n   g   >      
   #   i   n   c   l   u   d   e       <   i   o   s   t   r   e   a   m   >      
      
   u   s   i   n   g       n   a   m   e   s   p   a   c   e       s   t   d   ;      
      
      
      
   B   u   c   h   e   r   o   n   :   :   B   u   c   h   e   r   o   n   (       V   i   l   l   a   g   e   o   i   s   *       v       )       :       C   o   m   p   e   t   e   n   c   e   (       v   -   >   g   e   t   _   V   i   l   l   a   g   e   (   )       )       {      
   	   i   d   _       =       v   -   >   g   e   t   _   i   d   (   )   ;      
   	   n   o   m   _       =       v   -   >   g   e   t   _   N   o   m   (   )   ;      
   	   d   e   s   c   r   i   p   t   i   o   n   _       =       "   B   u   c   h   e   r   o   n   "   ;      
   	   v   i   l   l   a   g   e   o   i   s   _       =       v   ;      
   }      
      
      
   B   u   c   h   e   r   o   n   :   :   ~   B   u   c   h   e   r   o   n   (   )       {   }      
      
      
      
   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /      
   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /      
   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /      
      
      
      
   s   t   r   i   n   g       B   u   c   h   e   r   o   n   :   :   g   e   t   _   D   e   s   c   r   i   p   t   i   o   n   (   )       {      
   	   r   e   t   u   r   n       (       v   i   l   l   a   g   e   o   i   s   _   -   >   g   e   t   _   D   e   s   c   r   i   p   t   i   o   n   (   )       +       "   ,       "       +       d   e   s   c   r   i   p   t   i   o   n   _       )   ;      
   }      
      
   /   /   r   e   d   �   f   i   n   i   t       l   a       r   �   c   o   l   t   e       d   u       b   o   i   s       p   o   u   r       l   e   s       v   i   l   l   a   g   e   o   i   s       b   u   c   h   e   r   o   n   s   .       R   e   n   v   o   i   e       5       u   n   i   t   �   s       e   t       b   a   i   s   s   e       s   o   n       �   n   e   r   g   i   e   ,       s   '   i   l       a       a   s   s   e   z       d   '   �   n   e   r   g   i   e       p   o   u   r       f   a   i   r   e       l   '   a   c   t   i   o   n   .      
   i   n   t       B   u   c   h   e   r   o   n   :   :   r   e   c   o   l   t   e   r   _   B   o   i   s   (   )       {      
                   i   f       (   e   n   e   r   g   i   e   _       <       1   )   {      
                                   c   o   u   t       <   <       e   n   d   l       <   <       n   o   m   _       <   <       "   ,       a       b   e   a   u       e   t   r   e       u   n       p   r   o       p   o   u   r       c   o   u   p   e   r       d   u       b   o   i   s   ,       i   l       e   s   t       t   r   o   p       f   a   t   i   g   u   e   .   .   .   "   ;      
                                   r   e   t   u   r   n       0   ;      
                   }       e   l   s   e       {      
                                   c   o   u   t       <   <       e   n   d   l       <   <       n   o   m   _       <   <       "       c   o   u   p   e       d   u       b   o   i   s       c   o   m   m   e       u   n       p   r   o       !   "   ;      
                                   -   -   e   n   e   r   g   i   e   _   ;      
                                   r   e   t   u   r   n       5   ;      
                   }      
   }      
      
   v   o   i   d       B   u   c   h   e   r   o   n   :   :   a   f   f   i   c   h   e   r   (   )       {      
   	   v   i   l   l   a   g   e   o   i   s   _   -   >   a   f   f   i   c   h   e   r   (   )   ;      
   	   c   o   u   t       <   <       "   ,       "       <   <       d   e   s   c   r   i   p   t   i   o   n   _   ;      
   }      
