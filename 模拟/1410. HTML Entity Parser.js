/**
 * @param {string} text
 * @return {string}
 */

function process(str) {
  var arrEntities={'lt':'<','gt':'>','apos':"'",'amp':'&','quot':'"','frasl':'/'};
  return str.replace(/&(lt|gt|apos|amp|quot|frasl);/ig,function(all,t){
    return arrEntities[t];
  });
}

var entityParser = function(text) {
    return process(text);
};
